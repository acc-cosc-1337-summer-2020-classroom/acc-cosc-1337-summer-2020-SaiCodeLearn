//write include statements
#include<iostream>
#include<string>
#include "decisions.h"
#include <iomanip>

//These are the commands we will be using - declared to make programming easier
using std::cout; 
using std::cin; 
using std::string;
using std::fixed;
using std::setprecision;

/*
In main write code to capture a letter_grade and credit_hours from the keyboard:


Grade   Credit Hours	grade_points   credit_points
A          3            4              12
B          3            3               9
C          3            2               6
-----------------------------------------------
           9                           27
After each user input convert the Grade to grade points by calling the get_grade_points function, and
keep a running total for both credit_points and credit_hours.

Call the calculate_gpa function with its arguments.
The GPA should calculate to 3.0, make sure to display it before program exits.

Display:
GPA 3.0

*/
int main() 
{

	//Letter_grade(A, B, C, D, F) are individual strings 
	string letter_grade; 

	//Create three integer variables to record credit hours, sum of credit hours
	//and total sum of credit points
	int credit_hours, sum_credit_hours{0}, sum_credit_points{0};

	//Create a double variable for the gpa we need to calculate later
	double gpa;

	//Creates a char variable so that user can continue the program if they want 
	string choice;

	// Do while loop allows user to enter data how many ever times they need
	do
	{	
		//Enter letter grade and credit hours for further calculation
		cout << "\nEnter letter grade(as a Capital Letter): ";
		cin >> letter_grade;
		cout << "Enter credit hours: ";
		cin >> credit_hours;

		//Total sum of credit points = current sum of credit points +
		//(letter grade converted to grade points * credit hours for a class)
		sum_credit_points += get_grade_points(letter_grade)  * credit_hours;
		sum_credit_hours += credit_hours;

		//This allows user to determine if they want to continue with entering or not
		cout << "\nIf you want to enter letter grade and credit hours for another class -\n";
		cout << "Type Yes, or yes, in order to continue: "; 
		cin >> choice;

		//Below are the required conditions to continue entering data
	} while (choice == "Yes" || choice == "yes");
	
	
	//gpa variable is calculated, formatted, displayed
	gpa = calculate_gpa(sum_credit_hours, sum_credit_points);
	cout << fixed << setprecision(2);
	cout << "\nGPA: " << gpa;

	//Program success!
	return 0;
}