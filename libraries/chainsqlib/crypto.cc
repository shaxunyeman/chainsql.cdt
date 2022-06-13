#include "core/chainsql/crypto.h"

namespace chainsql {
    namespace internal_use_do_not_use
    {
        extern "C"
        {
            struct __attribute__((aligned(16))) capi_checksum160
            {
                uint8_t hash[20];
            };
            struct __attribute__((aligned(16))) capi_checksum256
            {
                uint8_t hash[32];
            };
            struct __attribute__((aligned(16))) capi_checksum512
            {
                uint8_t hash[64];
            };

            __attribute__((chainsql_wasm_import)) 
            uint32_t sha256(const char *data, uint32_t length, void* capi_checksum256);

            __attribute__((chainsql_wasm_import)) 
            uint32_t sha1(const char *data, uint32_t length, void* capi_checksum160);

            __attribute__((chainsql_wasm_import)) 
            uint32_t sha512(const char *data, uint32_t length, void* capi_checksum512);
        }
    }

    checksum256 sha256(const char *data, uint32_t length)
    {
        internal_use_do_not_use::capi_checksum256 hash;
        internal_use_do_not_use::sha256(data, length, &hash);
        return {hash.hash};
    }

    checksum160 sha1(const char *data, uint32_t length)
    {
        internal_use_do_not_use::capi_checksum160 hash;
        internal_use_do_not_use::sha1(data, length, &hash);
        return {hash.hash};
    }

    checksum512 sha512(const char *data, uint32_t length)
    {
        internal_use_do_not_use::capi_checksum512 hash;
        internal_use_do_not_use::sha512(data, length, &hash);
        return {hash.hash};
    }
}