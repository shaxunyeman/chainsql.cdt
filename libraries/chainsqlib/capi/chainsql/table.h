#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    __attribute__((chainsql_wasm_import))
    int32_t create_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t update_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t delete_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t rename_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t drop_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t grant_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t query_table(const void *data, int32_t size);

     __attribute__((chainsql_wasm_import))
    int32_t record_lines(int32_t handle);

     __attribute__((chainsql_wasm_import))
    int32_t get_colunms(int32_t handle);

     __attribute__((chainsql_wasm_import))
    int32_t get_colunm_value(int32_t handle,
                             int32_t record_index, int32_t col_index,
                             void *col_buffer, int32_t *col_buf_size,
                             void *value_buffer, int32_t *value_buf_size);

     __attribute__((chainsql_wasm_import))
    void transaction_begin();

     __attribute__((chainsql_wasm_import))
    void transaction_commit();
#ifdef __cplusplus
}
#endif