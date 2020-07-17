//engineer.cpp
#include "engineer.h"

//Calculate and Return pay for engineer pointer
double Engineer::get_pay() const
{
    return base_pay + bonus;
}