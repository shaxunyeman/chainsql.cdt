#include "chainsql/intrinsics.hpp"

using namespace chainsql::native;

extern "C" {
   int32_t read_action_data( void* msg, int32_t len ) {
      return intrinsics::get().call<intrinsics::read_action_data>(msg, len);
   }

   int32_t action_data_size() {
      return intrinsics::get().call<intrinsics::action_data_size>();
   }

   void set_action_return_value(void *return_value, int32_t size) {
      return intrinsics::get().call<intrinsics::set_action_return_value>(return_value, size);
   }

   void chainsql_assert(int32_t test, const void *msg)
   {
      return intrinsics::get().call<intrinsics::chainsql_assert>(test, msg);
   }
}