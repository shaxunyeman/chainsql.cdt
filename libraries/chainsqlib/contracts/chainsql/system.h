#pragma once

#include <stdint.h>

namespace chainsql {

     __attribute__((chainsql_wasm_import))
    uint64_t current_time_point();

     __attribute__((chainsql_wasm_import))
    uint64_t current_block_time();

} // namespace chainsql