#include "chainsqlib/core/chainsql/check.h"
#include "chainsqlib/contracts/chainsql/contract.h"

class [[chainsql::contract]] hello : public chainsql::contract {
public:
    using contract::contract;

    [[chainsql::action]]
    void hi()
    {
    }

private:
    void echo(const char *s)
    {
    }
};

//CHAINSQL_DISPATCH(hello, (hi))