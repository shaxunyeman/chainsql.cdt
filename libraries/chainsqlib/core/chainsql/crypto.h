#pragma once

#include <stdint.h>
#include "fixed_bytes.h"

namespace chainsql {
   checksum256 sha256( const char* data, uint32_t length );
   checksum160 sha1( const char* data, uint32_t length );
   checksum512 sha512( const char* data, uint32_t length );
}