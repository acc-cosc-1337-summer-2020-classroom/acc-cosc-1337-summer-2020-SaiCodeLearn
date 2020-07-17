//sales_employee.h
#include "employee.h"

#ifndef SALES_EMPLOYEE_H
#define SALES_EMPLOYEE_H

//Derived SalesEmployee class
class SalesEmployee : public Employee
{
public:
    SalesEmployee() : SalesEmployee(0.0, 0.0, 0.0){} //Default constructor
    SalesEmployee(double h, double r, double com) : hours{h}, rate{r}, commission{com}{} //Constructor that accepts values for SalesEmployee pay
    double get_pay() const; //Implementation in sales_employee.cpp
    ~SalesEmployee(){} //Destructor

//Respective private variables used in derived get_pay
private:
    double hours;
    double rate;
    double commission;
};

#endif