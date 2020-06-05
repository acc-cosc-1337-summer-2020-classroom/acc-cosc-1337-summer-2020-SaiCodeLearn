//write include statements
#include "input.h"
#include<iostream>
//write namespace using statements

/*
Capture units and rate values from keyboard.
Call the get_total function by passing units and rates variables to it.
Save the get_total return value to a variable named total.
Display the total:

Total: 100

*/

using std::cout;      using std::cin;

int main() 
{
	int units;
	double rate;

	cout<<"Enter Units: ";
	cin>>units;
	cout<<"Enter rate: ";
	cin>>rate;

	double total = get_total(units, rate);

	cout<<"Total: "<<total;
	return 0;
}