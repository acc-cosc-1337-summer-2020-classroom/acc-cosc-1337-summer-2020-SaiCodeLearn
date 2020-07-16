#include<iostream>
#include<cctype>

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
	first_name[3] = '\0';//Don't forget this at the end
	return 0;
}



