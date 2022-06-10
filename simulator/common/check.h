#pragma once

#include <stdint.h>
#include <string>
#include <exception>

namespace chainsql {
  inline void check(bool test, const void* msg, uint32_t msg_len) {
    if(test == false) {
      std::string error((const char*)msg, msg_len);
      throw std::runtime_error(error);
    }
  }

  inline void check(bool test, const void* msg) {
    check(test, msg, strlen((const char*)msg));
  }
}
