#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ref_pointers.h"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

/*TEST_CASE("Fucntion value, reference, pointer, pointer constant")
{
	int n1=1, n2=3, n3=3,n4=4;

	val_ref_ptr_cptr(n1,n2,&n3,&n4);//Pointers require reference

	REQUIRE(n1 == 1);
	REQUIRE(n2 == 5);
	REQUIRE(n3 == 10);
	REQUIRE(n4 == 4);
}*/

TEST_CASE("Test Vector size stack variables for copies")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());

	v1.set_size(5); //Purposely changed size of v1 to make them not equal
	REQUIRE(v1.Size() != v2.Size());

	//Memberwise copy works with Stack Variables!
}

TEST_CASE("Test Vector Heap Variable for copies")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.get_element(1) == v2.get_element(1));

	v1.set_element_value(1, 5);
	REQUIRE(v1.get_element(1) == v2.get_element(1));
	//This is to show the Class Copy dynamic Memory Issue

}


