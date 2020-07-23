//
#include <cstddef>
#include<stddef.h>//For size_t

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
    Vector(size_t sz);
    Vector(const Vector& v);//copy constructor - RULE OF 3 C++98
    Vector& operator=(const Vector & v);//Copy Assignment RULE OF 3 C++ 98
    Vector(Vector&& v);//move constructor cpp 11 Rule of 5 
    Vector& operator=(Vector&& v);//move assignment cpp 11 Rule of 5
    size_t Size()const{return size;} //Allows to create a test case
    int& operator[](size_t i){return elements[i];}
    int& operator[](size_t i)const{return elements[i];}
    void set_size(size_t sz){size = sz;}
    //now we can get rid of the below because of overload
    //void set_element_value(size_t index, int value){elements[index] = value;}
    //int get_element(size_t index){return elements[index];}
    ~Vector();//Destructor to release memory - RULE OF 3 C++ 98
private:
    size_t size;
    int *elements;
};

//free function - not part of the vector class
void use_stack_vector();
void use_heap_vector();
Vector get_vector();


#endif
