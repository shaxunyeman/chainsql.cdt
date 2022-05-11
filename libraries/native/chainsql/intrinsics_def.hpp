#pragma once

#include <utility>
#include <functional>
#include <type_traits>

#include <chainsqlib/capi/action.h>
#include <chainsqlib/capi/system.h>

namespace chainsql { namespace native {
   template <typename... Args, size_t... Is>
   auto get_args_full(std::index_sequence<Is...>) {
       std::tuple<std::decay_t<Args>...> tup;
       return std::tuple<Args...>{std::get<Is>(tup)...};
   }

   template <typename R, typename... Args>
   auto get_args_full(R(Args...)) {
       return get_args_full<Args...>(std::index_sequence_for<Args...>{});
   }

   template <typename R, typename... Args>
   auto get_args(R(Args...)) {
       return std::tuple<std::decay_t<Args>...>{};
   }

   template <typename R, typename Args, size_t... Is>
   auto create_function(std::index_sequence<Is...>) {
      return std::function<R(typename std::tuple_element<Is, Args>::type ...)>{
         [](typename std::tuple_element<Is, Args>::type ...) {
            chainsql_assert(false, "unsupported intrinsic"); 
            return (R)0;
         }
      };
   }

#define INTRINSICS(intrinsic_macro) \
intrinsic_macro(read_action_data) \
intrinsic_macro(action_data_size) \
intrinsic_macro(set_action_return_value) \
intrinsic_macro(chainsql_assert)


#define CREATE_ENUM(name) \
   name,

#define GENERATE_TYPE_MAPPING(name) \
   struct __ ## name ## _types { \
      using deduced_full_ts = decltype(chainsql::native::get_args_full(::name)); \
      using deduced_ts      = decltype(chainsql::native::get_args(::name)); \
      using res_t           = decltype(std::apply(::name, deduced_ts{})); \
      static constexpr auto is = std::make_index_sequence<std::tuple_size<deduced_ts>::value>(); \
   };

#define GET_TYPE(name) \
   decltype(create_function<chainsql::native::intrinsics::__ ## name ## _types::res_t, \
         chainsql::native::intrinsics::__ ## name ## _types::deduced_full_ts>(chainsql::native::intrinsics::__ ## name ## _types::is)),

#define REGISTER_INTRINSIC(name) \
   create_function<chainsql::native::intrinsics::__ ## name ## _types::res_t, \
         chainsql::native::intrinsics::__ ## name ## _types::deduced_full_ts>(chainsql::native::intrinsics::__ ## name ## _types::is),

}} //ns chainsql::native
