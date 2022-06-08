#pragma once

#include <stdint.h>
#include <stdarg.h>

#include "chainsqlib/contracts/chainsql/contract.h"

class [[chainsql::contract]] math : public chainsql::contract {
public:
    using contract::contract;

    [[chainsql::action]]
    int add(int a, int b);

    [[chainsql::action]] 
    int mult(int a, int b);
};