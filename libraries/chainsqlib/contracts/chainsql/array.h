#pragma once

#include <tuple>

#include <chainsql/map.h>
#include <chainsql/storage.h>
#include <chainsql/print.h>

namespace chainsql::kv {

    template <chainsql::name::raw TableName, typename V>
    class array
    {
    public:
        constexpr static inline uint8_t magic = 2;
        constexpr static inline name table_name = name{static_cast<uint64_t>(TableName)};
        using value_t = V;
        using origin_type = chainsql::kv::map<chainsql::name(TableName), int, V>;
        using origin_value_t = typename origin_type::writable_wrapper;

        static const key_type state_key()
        {
            static key_type prfx = chainsql::detail::const_pack(magic, table_name, chainsql::name("array.index"));
            return prfx;
        }

        void append(const value_t &v)
        {
            int32_t index = size();
            (*this)[index] = v;
            inc();
        }

        origin_value_t operator[](const int32_t index)
        {
            return impl_[index];
        }

        inline bool contains(const int32_t index) const
        {
            return impl_.contains(index);
        }

        void remove(const int32_t index)
        {
            int32_t s = size();
            sub();
            impl_.erase(index);
            update(index, s);
        }

        int32_t size()
        {
            int32_t current_index = 0;
            chainsql::getState(state_key(), current_index);
            return current_index;
        }

    private:
        void inc()
        {
            int32_t current_index = 0;
            chainsql::getState(state_key(), current_index);
            chainsql::setState(state_key(), ++current_index);
        }

        void sub()
        {
            int32_t current_index = 0;
            chainsql::getState(state_key(), current_index);
            if(current_index > 0)
                chainsql::setState(state_key(), --current_index);
        }

        void update(int32_t from, int32_t to)
        {
            if(to - 1 == from)
                return;

            for(int32_t i = from + 1; i < to; i++) {
                value_t v = (*this)[i].element.value;
                (*this)[from++] = v;
            }
        }

        origin_type impl_;
    };
}