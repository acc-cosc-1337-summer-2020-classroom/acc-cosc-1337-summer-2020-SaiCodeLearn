//
#include <cstddef>
#include<stddef.h>//For size_t

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template<typename T>//Will support any data type with template
class Vector
{
public:
    Vector();
    Vector(size_t sz);
    Vector(const Vector<T>& v);//copy constructor - RULE OF 3 C++98
    Vector<T>& operator=(const Vector<T> & v);//Copy Assignment RULE OF 3 C++ 98
    Vector(Vector<T>&& v);//move constructor cpp 11 Rule of 5 
    Vector<T>& operator=(Vector<T>&& v);//move assignment cpp 11 Rule of 5
    size_t Size()const{return size;} //Allows to create a test case
    size_t Capacity()const{return space;}
    void Reserve(size_t new_allocation);
    void Resize(size_t new_allocation);//This will collaborate with reserve
    void PushBack(T value);
    T& operator[](size_t i){return elements[i];}
    int& operator[](size_t i)const{return elements[i];}
    ~Vector();//Destructor to release memory - RULE OF 3 C++ 98

private://Initialize class in the same order 
    size_t size;
    T *elements;
    size_t space;
    const int RESERVE_DEFAULT_SIZE{8};//What most vendors give
    const int RESERVE_DEFAULT_MULTIPLIER{2};
};

//free function - not part of the vector class
void use_stack_vector();
void use_heap_vector();
//Vector get_vector();


#endif
