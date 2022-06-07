#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
    __attribute__((chainsql_wasm_import))
    int32_t read_action_data(void *msg, int32_t len);

     __attribute__((chainsql_wasm_import))
    int32_t action_data_size();

     __attribute__((chainsql_wasm_import))
    void set_action_return_value(void *return_value, int32_t size);
#ifdef __cplusplus
}
#endif