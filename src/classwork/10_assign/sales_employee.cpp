//sales_employee.cpp
#include "sales_employee.h"

//calculate & return pay for SalesEmployee
double SalesEmployee::get_pay() const
{
    return (hours * rate) + commission;
}

