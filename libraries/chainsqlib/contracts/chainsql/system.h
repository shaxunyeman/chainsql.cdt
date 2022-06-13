#pragma once

#include <stdint.h>

#include "../../core/chainsql/fixed_bytes.h"

namespace chainsql {
    namespace internal_use_do_not_use
    {
        extern "C"
        {
            struct __attribute__((aligned(16))) capi_hash256{ uint8_t hash[32];};

            __attribute__((chainsql_wasm_import))
            uint64_t get_balance(const void* address);

            __attribute__((chainsql_wasm_import))
            void get_block_hash(uint32_t seq, void* hash);

            __attribute__((chainsql_wasm_import))
            void selfdestruct(void* to);
        }
    }
    
    uint64_t get_balance(const account_id &account)
    {
        return internal_use_do_not_use::get_balance(account.data());
    }

    hash256 get_block_hash(uint32_t seq)
    {
        internal_use_do_not_use::capi_hash256 hash;
        internal_use_do_not_use::get_block_hash(seq, &hash);
        return {hash.hash};
    }

    void self_destruct(account_id &account)
    {
        return internal_use_do_not_use::selfdestruct(account.data());
    }
} // namespace chainsql