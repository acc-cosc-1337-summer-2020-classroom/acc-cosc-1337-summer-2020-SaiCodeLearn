//Write the include statement for types.h here

//Write include for capturing input from keyboard and displaying output to screen
#include "types.h"
#include<iostream>


int main() 
{
	auto num = 0;
	std::cout<<"Enter number: ";
	std::cin>>num;

	int result = multiply_numbers(num);

	std::cout<<"Result is:"<<result<<"\n";

	auto num1 = 4;
	result = multiply_numbers(num1);
	std::cout<<"Result is:"<<result;
	return 0;
}

