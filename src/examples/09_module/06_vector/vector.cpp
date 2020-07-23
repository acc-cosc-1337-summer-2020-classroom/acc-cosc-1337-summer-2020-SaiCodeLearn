#include "vector.h"
#include <iostream>

//
Vector::Vector(size_t sz)
: size{sz}, elements{new int[sz]}
{
    for(size_t i=0; i<sz; ++i)
    {
        elements[i] = 0;
    }
}

/*
1-Initialize size
2. Intialize memory
3- Copy element values from v1 into v2
*/

Vector::Vector(const Vector& v)
: size{v.size}, elements{new int[v.size]}
{
    for(size_t i=0; i<size; ++i)
    {
        elements[i] = v.elements[i];
    }
}

/*
1-Create temporary memory
2-Copy v1 values into temporary memory
3-Delete class(v2) elements memory
4-Point elements memory to temporary memory
5-Return a reference to this vector
*/
Vector& Vector::operator=(const Vector & v)
{
    int *temp = new int[v.size];
    
    for(size_t i =0; i<v.size; ++i)
    {
        temp[i] = v.elements[i];
    }

    delete[] elements;
    elements = temp;
    size = v.size;

    return *this;
}

/*
1 - Get dynamic memory from v1(temp)
2 - get the size
3 - set size and elements of temp object to 0 and nullptr
    -We are not deleting this pointer yet
*/
Vector::Vector(Vector&& v)
    :size{v.size}, elements{v.elements}
{
    v.size = 0;
    v.elements = nullptr;//
}

/*
1-de allocate original dynamic memory
2-get the dynamic memory from v1
3-get the size from v1
4-set v1.elements to nullptr
5-v1.size to 0
6-return a self reference
*/
Vector& Vector::operator=(Vector&& v)//v1 is already in memory
{
    delete[] elements;//This would delete the original memory(v1)
    elements = v.elements; //This transfers memory from the v to v1
    size = v.size;
    v.elements = nullptr;
    v.size = 0;

    return *this;//Returns v1
}

Vector::~Vector()
{   
    std::cout<<"\nrelease memory";
    delete[] elements;
}


//NOT PART OF THE VECTOR CLASS!!!
void use_stack_vector()
{
    Vector v1(3);//delete will be automatically called - No memory leak
}

void use_heap_vector()
{
    Vector *v1 = new Vector(3);//Creates dynamic memory

    //delete memory here - Call the destructor here
    delete v1;
    v1 = nullptr;
}

Vector get_vector()
{   
    //This passes by value
    Vector v1(3);
    return v1;
}