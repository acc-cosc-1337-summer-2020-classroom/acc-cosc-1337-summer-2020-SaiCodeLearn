//engineer.h
#include "employee.h"

#ifndef ENGINEER_H
#define ENGINEER_H

//Derived Engineer class
class Engineer : public Employee
{
public:
    Engineer() : Engineer(0.0, 0.0){} //Default constructor
    Engineer(double bp, double bn) : base_pay{bp}, bonus{bn}{} //Constrcutor that accepts values for engineer pay
    double get_pay() const; //Implementation in engineer.cpp
    ~Engineer(){} //Destructor to delete memory

//Respective private variables
private:
    double base_pay;
    double bonus;
};

#endif