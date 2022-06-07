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
    const void *get_tx_context();

     __attribute__((chainsql_wasm_import))
    uint64_t chainsql_contract_address();

     __attribute__((chainsql_wasm_import))
    int32_t account_exists(const void *address, int32_t len);

     __attribute__((chainsql_wasm_import))
    int32_t get_balance(void *balance_buf, int32_t *buf_size);

     __attribute__((chainsql_wasm_import))
    int32_t get_block_hash(int64_t block, void *hash_buf, int32_t *buf_size);

     __attribute__((chainsql_wasm_import))
    void emit_log(const void *topics, int32_t topic_number, const void *data, int32_t data_size);

     __attribute__((chainsql_wasm_import))
    void* hash256(const void* data, uint32_t size);

     __attribute__((chainsql_wasm_import))
    int64_t account_set(int32_t flag, int32_t set);

     __attribute__((chainsql_wasm_import))
    int64_t transfer_fee_set(const void *rate, int32_t rate_len,
                             const void *min, int32_t min_len,
                             const void *max, int32_t max_len);
    
     __attribute__((chainsql_wasm_import))
    int64_t trust_set(const void *value, int32_t value_len,
                      const void *currency, int32_t currency_len);
    
     __attribute__((chainsql_wasm_import))
    int64_t trust_limit(const void *currency, int32_t currency_len, int64_t power,
                        const void *gateway, int32_t geteway_len);

     __attribute__((chainsql_wasm_import))
    int64_t gateway_balance(const void *currency, int32_t currency_len, int64_t power,
                            const void *gateway, int32_t geteway_len);

     __attribute__((chainsql_wasm_import))
    int64_t pay(const void *to, int32_t to_len,
                const void *value, int32_t value_len,
                const void *max, int32_t max_len,
                const void *currency, int32_t currency_len,
                const void *gateway, int32_t gateway_len);
#ifdef __cplusplus
}
#endif