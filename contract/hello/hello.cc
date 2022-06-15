#include <chainsql/contract.h>
#include <chainsql/print.h>
#include <chainsql/string.h>

CONTRACT hello : public chainsql::contract {
public:
    using contract::contract;

    ACTION void hi(const chainsql::string &msg)
    {
        chainsql::print_f("hello %\n", msg);
    }
};