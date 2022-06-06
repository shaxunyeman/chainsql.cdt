#include <chainsql/chainsql.hpp>
using namespace chainsql;

CONTRACT hello : public contract {
   public:
      using contract::contract;

      ACTION hi( name nm );
      ACTION check( name nm );

      using hi_action = action_wrapper<"hi"_n, &hello::hi>;
      using check_action = action_wrapper<"check"_n, &hello::check>;
};

ACTION hello::hi( name nm ) {
   print_f("Name : %\n", nm);
}

ACTION hello::check( name nm ) {
   print_f("Name : %\n", nm);
   chainsql::check(nm == "hello"_n, "check name not equal to `hello`");
}
