#include "swap.h"


swap::swap(void)
{
}


swap::~swap(void)
{
}

void swap::SwapByMinus(int& a, int& b)
{
       a = a - b;
       b = b + a;
       a = b - a;
}

void swap::SwapByXor(int& a, int& b)
{
       a = a ^ b;
       b = a ^ b;
       a = a ^ b;
}

