//Include the header file
#include "dna.h"

/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:

Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
    //Two doubles - One to keep track of G's and C's, other for string length
    double gc_counter{0}, size(dna.size());  

    //For loop to iterate between DNA string letters
    for(std::size_t i=0; i < size; i++)
    {   
        //If 'G' or 'C' is found, our GC counter increments by 1
        if( dna[i] == 'G' || dna[i] == 'C') 
        {
            gc_counter ++;
        }

    }

    //Divide gc counter value by size -> Return as double 
    return gc_counter / size;
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/

string get_reverse_string(string dna)
{   
    //Create local variable string reverse
    string reverse;

    //Iterate through each letter backwards - from last letter to first
    for(std::size_t i = dna.size(); i > 0; --i)
    {   
        //Append each letter to the "reverse" string
        reverse += dna[i-1]; 
    }

    //Return the reversed DNA string for further use
    return reverse;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna)
{   
    //local variable complement created - first using the reversed string function
    string complement = get_reverse_string(dna);

    //Iterate through each letter of the reversed DNA string
    for(std::size_t i = 0; i <= complement.size(); ++i )
    {   
        //I used an if-else statement here - just for the sake of using it - but a switch statement could also work
        //If the current letter is 'A', replace with 'T'
        if(complement[i] == 'A')
        {
            complement[i] = 'T';
        }

        //If the current letter is 'T' replace with 'A'
        else if (complement[i] == 'T')
        {
            complement[i] = 'A';
        }

        //If the current letter is 'G' replace with 'C'
        else if (complement[i] == 'G')
        {
            complement[i] = 'C';
        }

        //If the current letter is 'C' replace with 'G'
        else
        {
            complement[i] = 'G';
        }  
    }
    //Complemented is fully created and returned
    return complement;
}


