#include "contracts/chainsql/system.h"

namespace chainsql {
    extern "C"
    {
        __attribute__((chainsql_wasm_import))
        uint64_t current_time();
    }

    uint64_t current_time_point()
    {
        return current_time();
    }

    uint64_t current_block_time()
    {
        return current_time_point();
    }
}