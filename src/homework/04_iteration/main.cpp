//write include statements 
#include "dna.h"
#include <iostream>
#include <string>
//write using statements
using std::cin; using std::cout; using std::string;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{	
	//Create two char variables for user input(options 1,2 and Y/y to continue)
	char choice, option;
	//Creates double for gc percentage as gc_content
	double gc_content;
	//string variable created for dna(input stuff)
	string dna;

	//do while loop so commands are run so long condition is followed
	do
	{	
		//Choose either option 1 or 2  
		cout<<"\nEnter 1 if you want to find the GC content(%)\n";
		cout<<"		Or\nEnter 2 to find a DNA's complement: ";
		cin>>option;

		//Regardless of option you choose - must enter DNA sequence
		cout<<"\nEnter a DNA string(all CAPS): ";
		cin>>dna;

		if(option == '1') //If option is 1 - Find the GC turnout in the DNA strand
		{
			gc_content = get_gc_content(dna);
			cout<<"\nGC Content is: "<<gc_content;
		}

		else if(option == '2') //If option is 2 - Find the DNA's complement
		{
			auto complement = get_dna_complement(dna);
			cout<<"\nDNA complement is: "<<complement;
		}
		
		//This is to check if user wants to continue
		cout<<"\nIf you want to continue, enter y or Y: ";
		cin >> choice;
		
	} while (choice == 'y' || choice == 'Y');

	return 0; //Program success!
}