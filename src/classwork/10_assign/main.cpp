//main.cpp
#include "employee.h"
#include "engineer.h"
#include "sales_employee.h"
#include <iomanip>

using std::cout;

int main()
{
  Employee *engineer = new Engineer(1500, 400); //Raw pointer - class Employee of Engineer type
  Employee *salesman = new SalesEmployee(40, 10, 500); //Raw pointer - class Employee or SalesEmployee type
  cout<<"Pay of engineer: $"<<std::fixed<<std::setprecision(2)<<engineer->get_pay(); //Format and output engineer pay
  cout<<"\nPay of salesman: $"<<std::fixed<<std::setprecision(2)<<salesman->get_pay(); //Format and output sales employee pay
  
  //Delete dynamic memory for engineer pointer
  delete engineer;
  engineer = nullptr;

  //Delete dynamic memory for salesman(SalesEmployee) pointer
  delete salesman;
  salesman = nullptr;
  
  //Destructor from Employee class will display "deleted mem" twice total
  return 0; //Program success!
}