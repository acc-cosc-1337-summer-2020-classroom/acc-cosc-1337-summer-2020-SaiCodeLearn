#include<iostream>
#include<cctype>//For comparing looking at chars
#include "arrays_dyn_2.h"
#include<cstring>//for character arrays
#include<string>//Special string-> int
using std::cout;

int main() 
{	
	cout<<"Hello";
	char letter = 'a';//Chars do not know there size, we have to use functions to figure it out
	
	if(isupper(letter)) //cctype is included for isupper and lower
	{
		cout<<"Upper \n";
	}
	if(islower(letter))
	{
		cout<<"Lower \n";
	}
	if(isalpha(letter))
	{
		cout<<"Alpha \n";
	}
	if(isdigit(letter))
	{
		cout<<"number\n";
	}
	cout<<"Convert to Upper: "<<toupper(letter)<<"\n";//To convert lower to upper or upper to upper
	cout<<"Convert to lower: "<<tolower(letter)<<"\n";//To convert ot lower
	

	//Example of char array to fill elements from keyboard
	const int SIZE = 26;
	char name[SIZE];
	std::cin.getline(name, SIZE);
	cout<<"Name: "<<name<<"\n";

	//Iterate through the character arry to find special character
	int indx =0;
	while(name[indx] != '\0')
	{
		cout<<name[indx]<<"\n";
		indx++;
	}//C++ auto matically adds the \0 for us


	//Another example of the above
	cout<<"\n\n"

	//Have to initialize back to 0 to initiate 2nd array
	indx =0;
	char last_name[SIZE] = "Eisenhower";
	while(last_name[indx] != '\0')
	{
		cout<<last_name[indx]<<"\n";
		indx++;
	}//C++ automatically adds the \0 for us

	//If we are taking control then make sure to correctly terminate character array
	char first_name[SIZE];
	first_name[0] = 'J';
	first_name[1] = 'o';
	first_name[2] = 'e';
	first_name[3] = '\0';//Don't forget this at the end - If u put 26 - Garbage will show up
	cout<<"\nfirst name: "<<first_name<<"\n";//Will disply first name

	first_name[0] = 'j';//Modding char array values

	//Pointers and char arrays
	char *ptr_last_name = last_name;//Pointing to 'E' in Eisenhower
	cout<<"Last name by pointer: "<<ptr_last_name<<"\n";//Should display 'E'
	//Remember these are only stack arrays and pointers

	//use cstring header to find length of string
	display_chars(first_name, 4);
	cout<<"Length of first_name:"<<strlen(first_name)<<"\n";//length doesn't include '\0'
	cout<<"Length of last_name:"<<strlen(last_name)<<"\n";
	
	//Concatenation
	strcat(first_name, last_name);//Adding two strings together
	cout<<"Concatenate: "<<first_name<<"\n";//Concatenated string displayed

	//Conversion from string to integer
	int i = std::stoi("S");
	cout<<"Conversion: "<<i<<"\n";

	return 0;
}



