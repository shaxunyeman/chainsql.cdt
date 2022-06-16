#include "chainsql/intrinsics.hpp"

using namespace chainsql::native;

extern "C" {
   void chainsql_assert(int32_t test, const void *msg)
   {
      return intrinsics::get().call<intrinsics::chainsql_assert>(test, msg);
   }

   void chainsql_assert_message(int32_t test, const void *msg, int32_t msg_len)
   {
      return intrinsics::get().call<intrinsics::chainsql_assert_message>(test, msg, msg_len);
   }

   uint64_t get_balance(const void* address)
   {
      return intrinsics::get().call<intrinsics::get_balance>(address);
   }

   void get_block_hash(uint32_t block, void *hash_buf)
   {
      return intrinsics::get().call<intrinsics::get_block_hash>(block, hash_buf);
   }

   void msg_sender(void* address)
   {
      return intrinsics::get().call<intrinsics::msg_sender>(address);
   }

   void pay(void* to, uint64_t drops)
   {
      return intrinsics::get().call<intrinsics::pay>(to, drops);
   }
}