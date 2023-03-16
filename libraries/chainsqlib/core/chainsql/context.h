#pragma once

#include "fixed_bytes.h"

namespace chainsql {
    namespace internal_use_do_not_use
    {
        struct __attribute__((aligned(16))) capi_account_id{ uint8_t address[20];};

         __attribute__((chainsql_wasm_import))
        extern "C" void get_contract_address(void* address);

         __attribute__((chainsql_wasm_import))
        extern "C" void msg_sender(void* address);

         __attribute__((chainsql_wasm_import))
        extern "C" int64_t msg_value();
    }

    inline account_id current_context_contract() 
    { 
        internal_use_do_not_use::capi_account_id address;
        internal_use_do_not_use::get_contract_address(&address);
        return {address.address};
    }

    inline account_id sender()
    { 
        internal_use_do_not_use::capi_account_id address;
        internal_use_do_not_use::msg_sender(&address);
        return {address.address};
    }

    inline int64_t value()
    {
        return internal_use_do_not_use::msg_value();
    }
} // namespace chainsql
