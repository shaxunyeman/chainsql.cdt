#pragma once

#include <stdint.h>

namespace chainsql {
    using checksum160 = uint32_t;
    using checksum256 = uint32_t;
    using checksum512 = uint32_t;

   checksum256 sha256( const char* data, uint32_t length );
   checksum160 sha1( const char* data, uint32_t length );
   checksum512 sha512( const char* data, uint32_t length );
}