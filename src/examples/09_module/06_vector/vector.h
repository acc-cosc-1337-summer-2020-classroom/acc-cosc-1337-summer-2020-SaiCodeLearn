//
#include <cstddef>
#include<stddef.h>//For size_t

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
    Vector(size_t sz);
    size_t Size()const{return size;} //Allows to create a test case
    void set_size(size_t sz){size = sz;}

private:
    size_t size;
    int *elements;
};

#endif
