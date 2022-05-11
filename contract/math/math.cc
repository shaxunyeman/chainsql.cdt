#include <stdint.h>
#include <stdarg.h>

#include "chainsqlib/contracts/contract.h"

class math : public chainsql::contract {
public:
    using contract::contract;

    int add(int a, int b) {
        return a + b;
    }
};

CHAINSQL_DISPATCH(math, (add))