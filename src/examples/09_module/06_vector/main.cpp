//
#include "vector.h"
#include <iostream>
using std::cout;

int main()
{

    //Comment one or the other
    //use_stack_vector();
    //use_heap_vector();//Does not release memory without proper implementation
    
    int num {5};//this is an lvalue - we can reference it
    int &num_ref = num;//We take a reference of the address
    cout<<num_ref<<"\n";
    
    /*R values?*/ //Allow us access to concrete values to return a quick copy
    //The number 5 above is an Rvalue

        //Illegal declarations below//
    //------------------------------//
    //int &num_5_ref = 5;//We can't access this actual value
    //5 = num;

    //If we use this declaration, it works - &&
    /*int && num_5_ref = 5;
    cout<<"Rvalue ref: "<<num_5_ref<<"\n";
    
    num_5_ref = 10;
    cout<<"Rvalue ref: "<<num_5_ref<<"\n";*/

    Vector<int> v(3);
    //v = v; We dont want this because its unnecessary
    
    v.PushBack(5);
    v.PushBack(10);
    cout<<"Capacity: "<<v.Capacity();//Capacity should be 3
    for(size_t i =0; i<3; ++i)
    {
        cout<<v[i]<<"\n";//Should display 0 0 0 (all in newlines)
    }

    
    v.PushBack(7);//Size is 3
    v.PushBack(12);//Space must be added to elements array
    for(size_t i =0; i<v.Size(); ++i)
    {
        cout<<v[i]<<"\n";//Should display 0 0 0 (all in newlines)
    }
    cout<<"Capacity: "<<v.Capacity();//Capacity should be 6  
    return 0;
}

