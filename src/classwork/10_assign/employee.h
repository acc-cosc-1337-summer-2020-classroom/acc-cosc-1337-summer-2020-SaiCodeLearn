//employee.h
#include <iostream>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//Abstract employee class
class Employee
{
public:
    virtual double get_pay() const = 0;
    virtual ~Employee(){std::cout<<"\ndeleted mem";} //Virtual Destuctor which displays "deleted mem" after dynamic memory from pointer removed
};

#endif

