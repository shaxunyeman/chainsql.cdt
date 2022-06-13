#pragma once

#include <string>
#include <exception>

#include <wasm3_cpp.h>

namespace chainsql
{
    extern "C"
    {
        void chainsql_assert(int32_t test, const void *msg)
        {
            std::string message((const char *)msg);
            throw std::runtime_error(message);
        }

        void chainsql_assert_message(int32_t test, const void *msg, int32_t msg_len)
        {
            std::string message((const char *)msg, msg_len);
            throw std::runtime_error(message);
        }

        void chainsql_assert_code(int32_t, int64_t)
        {

        }

        uint64_t get_balance(const void *address)
        {
            return 0;
        }

        void get_block_hash(uint32_t seq, void *hash)
        {

        }

        void selfdestruct(void *to)
        {

        }

        uint32_t sha256(const char *data, uint32_t length, void *capi_checksum256)
        {
            return 0;
        }

        uint32_t sha1(const char *data, uint32_t length, void *capi_checksum160)
        {
            return 0;
        }

        uint32_t sha512(const char *data, uint32_t length, void *capi_checksum512)
        {
            return 0;
        }

        void msg_sender(void *address)
        {

        }

        void pay(void *to, uint64_t drops)
        {

        }
    }
}

namespace chainsql {
    void link_system(wasm3::module &mod) {
        mod.link_optional("*", "chainsql_assert", chainsql_assert);
        mod.link_optional("*", "chainsql_assert_message", chainsql_assert_message);
        mod.link_optional("*", "chainsql_assert_code", chainsql_assert_code);
        mod.link_optional("*", "get_balance", get_balance);
        mod.link_optional("*", "get_block_hash", get_block_hash);
        mod.link_optional("*", "selfdestruct", selfdestruct);
        mod.link_optional("*", "sha256", sha256);
        mod.link_optional("*", "sha1", sha1);
        mod.link_optional("*", "sha512", sha512);
        mod.link_optional("*", "msg_sender", msg_sender);
        mod.link_optional("*", "pay", pay);
    }
}