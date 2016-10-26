#include "my_math.h"
// global variable with static modifier makes it have file scope
static int counter = 0;

void resetCounter()
{
    counter = 0;
}

int incrementCounter()
{
    return ++counter;
}

int decrementCounter()
{
    return --counter;
}

int getCounter()
{
    return counter;
}

void setCounter(int newCount)
{
    counter = newCount;
}

int add(int v1, int v2)
{
    return ADD_INPLACE(v1, v2);
}

int subtract(int v1, int v2)
{
    return SUB_INPLACE(v1, v2);
}

int multiply(int v1, int v2)
{
    return MUL_INPLACE(v1, v2);
}

int divide(int v1, int v2)
{
    return DIV_INPLACE(v1, v2);
}

int modulus(int v1, int v2)
{
    return MOD_INPLACE(v1, v2);
}
