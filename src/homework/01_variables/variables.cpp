//Include statement for custom file "variables.h", where functions where defined
#include "variables.h"

//Example for reference- Not part of actual Meal program
/*int add_numbers(int num1, int num2)
{
	return num1 + num2;
}*/

//meal amount parameter sent to get_sales_tax_amount function
double get_sales_tax_amount(double meal_amount)
{	
	//Create a constant(unchanging) sales tax rate, this case 6.75% or .0675
	const double TAX_RATE = .0675;

	//return the value of meal amount times constant tax rate = sales tax amount
	return meal_amount * TAX_RATE;
}

//meal amount and tip_rate parameters sent to get_tip_amount function
double get_tip_amount(double meal_amount, double tip_rate)
{
	//return the product of meal amount and tip rate = tip value
	return meal_amount * tip_rate;
}

