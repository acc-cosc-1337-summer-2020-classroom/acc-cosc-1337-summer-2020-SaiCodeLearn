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