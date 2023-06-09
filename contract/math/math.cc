#include "math.h"

#include <chainsql/check.h>
#include <chainsql/print.h>

int math::add(int a, int b)
{
    int ret = a + b;
    chainsql::print_f("% + % = %\n", a, b, ret);
    return ret;
}

int math::mult(int a, int b)
{
    int ret = a * b;
    chainsql::print_f("% * % = %\n", a, b, ret);
    return ret;
}