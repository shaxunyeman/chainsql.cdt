#include <chainsql/contract.h>
#include <chainsql/print.h>
#include <chainsql/string.h>

class [[chainsql::contract]] hello : public chainsql::contract {
public:
    using contract::contract;

    [[chainsql::action]]
    void hi(const chainsql::string &msg)
    {
        chainsql::print_f("hello %\n", msg);
    }
};