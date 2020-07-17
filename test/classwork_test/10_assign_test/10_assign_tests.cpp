#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "employee.h"
#include "engineer.h"
#include "sales_employee.h"

using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

//Testing if Engineer get_pay() with specific parameters works
TEST_CASE("Test class function Engineer::get_pay()")
{
	Employee *engineer =  new Engineer(1500,400);
	REQUIRE(engineer->get_pay() == 1900);
	delete engineer;
	engineer = nullptr;
}

//Testing if SalesEmployee get_pay() with specific parameters works
TEST_CASE("Test class function SalesEmployee::get_pay()")
{
	Employee *salesman = new SalesEmployee(40, 10, 500);
	REQUIRE(salesman->get_pay() == 900);
	delete salesman;
	salesman = nullptr;
}