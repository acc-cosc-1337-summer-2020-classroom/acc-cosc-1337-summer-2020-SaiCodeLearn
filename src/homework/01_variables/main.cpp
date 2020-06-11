//write include statements - "variables.h" is header file, <iostream> and <iomanip> are C++ standard libraries
#include "variables.h"
#include <iostream>
#include <iomanip>

/*Write namespace using statement for display(cout, cin) 
and fomatting(setprecision,fixed,setw).*/

using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;

/*
Main function
*/
int main()
{
	//Create variables for meal amount, tax amount, tip rate, tip amount, total 
	double meal_amount, tax_amount, tip_rate, tip_amount, total; 

	//Customer inputs cost of meal
	cout<< "Enter the meal amount $";
	cin>> meal_amount;  
	cout<<"\n"; 

	//Tax amount is calculated through get_sales_tax_amount function, total cost of meal is updated
	tax_amount = get_sales_tax_amount(meal_amount);
	total = meal_amount + tax_amount;
	
	////Customer inputs rate at which they tip
	cout<< "Enter the tip rate(as a decimal): ";
	cin>> tip_rate;
	cout<<"\n";

	//Tip amount calculated with get_tip_amount function
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	//New total meal cost updated with tip value
	total += tip_amount;

	/*Decimal formatting of receipt. 
	Meal Amount, Sales Tax, Tip Amount, and Total(Final) Cost displayed*/
	cout << fixed << setprecision(2);
	cout << "Meal Amount:" << setw(2) << "$" << meal_amount <<"\n";
	cout << "Sales Tax  :" << setw(2) << "$" << tax_amount <<"\n";
	cout << "Tip Amount :" << setw(2) << "$" << tip_amount <<"\n";
	cout << "Total      :" << setw(2) << "$" << total << "\n";

	//Program success!
	return 0;
}
