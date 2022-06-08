#include "core/chainsql/crypto.h"

namespace chainsql {
    namespace internal_use_do_not_use
    {
        extern "C"
        {
            __attribute__((chainsql_wasm_import)) 
            uint32_t sha256(const char *data, uint32_t length, char *buffer, uint32_t buf_size);

            __attribute__((chainsql_wasm_import)) 
            uint32_t sha1(const char *data, uint32_t length, char *buffer, uint32_t buf_size);

            __attribute__((chainsql_wasm_import)) 
            uint32_t sha512(const char *data, uint32_t length, char *buffer, uint32_t buf_size);
        }
    }

    checksum256 sha256(const char *data, uint32_t length)
    {
        checksum256 v;
        internal_use_do_not_use::sha256(data, length, (char*)&v, sizeof(v));
        return v;
    }

    checksum160 sha1(const char *data, uint32_t length)
    {
        checksum160 v;
        internal_use_do_not_use::sha1(data, length, (char*)&v, sizeof(v));
        return v;
    }

    checksum512 sha512(const char *data, uint32_t length)
    {
        checksum512 v;
        internal_use_do_not_use::sha1(data, length, (char*)&v, sizeof(v));
        return v;
    }
}