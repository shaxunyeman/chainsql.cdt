#include <chainsql/contract.h>
#include <chainsql/print.h>

class [[chainsql::contract]] hello : public chainsql::contract {
public:
    using contract::contract;

    [[chainsql::action]]
    void hi()
    {
        chainsql::print("hello peersafe\n");
    }
};