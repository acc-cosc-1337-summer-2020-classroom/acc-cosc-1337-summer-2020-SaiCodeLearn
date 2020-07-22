#include "vector.h"

//
Vector::Vector(size_t sz)
: size{sz}, elements{new int[sz]}
{
    for(size_t i=0; i<sz; ++i)
    {
        elements[i] = 0;
    }
}
