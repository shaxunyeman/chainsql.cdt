#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    __attribute__((chainsql_wasm_import))
    void chainsql_assert(int32_t test, const void *msg);

     __attribute__((chainsql_wasm_import))
    void chainsql_assert_message(int32_t test, const void *msg, int32_t msg_len);

    __attribute__((chainsql_wasm_import))
    uint64_t get_balance(const void* address);

    __attribute__((chainsql_wasm_import))
    void get_block_hash(uint32_t seq, void* hash);

    __attribute__((chainsql_wasm_import))
    void selfdestruct(void* to);

    __attribute__((chainsql_wasm_import)) 
    uint32_t sha256(const char *data, uint32_t length, void* capi_checksum256);

    __attribute__((chainsql_wasm_import))
    uint32_t sha1(const char *data, uint32_t length, void *capi_checksum160);

    __attribute__((chainsql_wasm_import))
    uint32_t sha512(const char *data, uint32_t length, void *capi_checksum512);

    __attribute__((chainsql_wasm_import))
    void msg_sender(void* address);

    __attribute__((chainsql_wasm_import))
    int64_t msg_value();

    __attribute__((chainsql_wasm_import))
    void pay(void* to, uint64_t drops);
#ifdef __cplusplus
}
#endif
