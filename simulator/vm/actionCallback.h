#pragma once

#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <vector>

#include <simulator/vm/action.h>
#include <wasm3_cpp.h>

namespace chainsql
{
    class actionCallback
    {
    public:
        using Result = std::vector<char>;

        std::function<int32_t(void *, int32_t)> read_action_data =
            std::bind(&actionCallback::read_action_data_impl, this, std::placeholders::_1, std::placeholders::_2);
        std::function<int32_t()> action_data_size = std::bind(&actionCallback::action_data_size_impl, this);
        std::function<void(void *, int32_t)> set_action_return_value =
            std::bind(&actionCallback::set_action_return_value_impl, this, std::placeholders::_1, std::placeholders::_2);

        actionCallback(const action &ac, wasm3::module &mod)
            : action_(ac)
        {
            mod.link("*", "read_action_data", &read_action_data);
            mod.link("*", "action_data_size", &action_data_size);
            mod.link_optional("*", "set_action_return_value", &set_action_return_value);
        }

        const action& Action() const {
            return action_;
        }

        Result result() 
        {
            return result_;
        }

    private:
        int32_t read_action_data_impl(void *msg, int32_t len)
        {
            int32_t size = std::min(len, (int32_t)action_.payload().size());
            std::memcpy(msg, action_.payload().c_str(), size);
            return size;
        }

        int32_t action_data_size_impl()
        {
            return action_.payload().size();
        }

        void set_action_return_value_impl(void *return_value, int32_t size)
        {
            if(size > 0) {
                result_.resize(size);
                std::memcpy(&result_[0], return_value, size);
            }
        }
    private:
        const action &action_;
        Result result_;

    };
} // namespace chainsql
