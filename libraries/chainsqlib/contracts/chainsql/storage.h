#pragma once

#include <vector>

#include "chainsqlib/core/chainsql/datastream.h"
#include "chainsqlib/core/chainsql/context.h"

namespace chainsql {
    /**
     * @brief Set the State object
     * 
     * @tparam KEY Key type
     * @tparam VALUE Value type
     * @param key Key
     * @param value Value
     */
    template <typename KEY, typename VALUE>
    inline void setState(const KEY &key, const VALUE &value) {
        std::vector<char> vecKey(pack_size(key));
        std::vector<char> vecValue(pack_size(value));
        datastream<char*> keyStream(vecKey.data(), vecKey.size());
        datastream<char*> valueStream(vecValue.data(), vecValue.size());
        keyStream << key;
        valueStream << value;
        kv::internal_use_do_not_use::kv_set(vecKey.data(), vecKey.size(), vecValue.data(), vecValue.size());
    }

    /**
     * @brief Get the State object
     * 
     * @tparam KEY Key type
     * @tparam VALUE Value type
     * @param key Key
     * @param value Value
     * @return size_t Get the length of the data
     */
    template <typename KEY, typename VALUE>
    inline size_t getState(const KEY &key, VALUE &value) {
        std::vector<char> vecKey(pack_size(key));
        datastream<char*> keyStream(vecKey.data(), vecKey.size());
        keyStream << key;
        uint32_t len = 0;
        kv::internal_use_do_not_use::kv_get(vecKey.data(), vecKey.size(), &len);
        if (len == 0){ return 0; }
        std::vector<char> vecValue(len);
        kv::internal_use_do_not_use::kv_get_data(vecKey.data(), vecKey.size(), 0, vecValue.data(), vecValue.size());

        datastream<char*> valueStream(vecValue.data(), vecValue.size());
        valueStream >> value;
        return len;
    }

    /**
     * @brief delete State Object
     * 
     * @tparam KEY Key type
     * @param key Key
     */
    template <typename KEY>
    inline void delState( const KEY &key) {
        std::vector<char> vecKey(pack_size(key));
        datastream<char*> keyStream(vecKey.data(), vecKey.size());
        keyStream << key;
        kv::internal_use_do_not_use::kv_erase(vecKey.data(), vecKey.size());
    }

}
