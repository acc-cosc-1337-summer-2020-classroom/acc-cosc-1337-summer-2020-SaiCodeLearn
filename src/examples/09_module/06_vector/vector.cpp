#include "vector.h"
#include <iostream>

//

template<typename T>
Vector<T>::Vector()
: size{0}, space{0}, elements{nullptr}
{

}

template<typename T>
Vector<T>::Vector(size_t sz)
: size{0}, elements{new T[sz]}, space{sz}
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
template<typename T>
Vector<T>::Vector(const Vector& v)
: size{v.size}, elements{new int[v.size]}//Rewatch video to fix this part
{
    for(size_t i=0; i<size; ++i)
    {
        elements[i] = v.elements[i];
    }
}

template<typename T>
/*
1-Create temporary memory
2-Copy v1 values into temporary memory
3-Delete class(v2) elements memory
4-Point elements memory to temporary memory
5-Return a reference to this vector
*/
Vector<T>& Vector<T>::operator=(const Vector<T> & v)
{   
    if(this == &v)//this prevents the same class being copied to itself
    {
        return *this;
    }

    T *temp = new T[v.size];
    
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
template<typename T>
Vector<T>::Vector(Vector<T>&& v)
    :size{v.size}, elements{v.elements}
{
    v.size = 0;
    v.elements = nullptr;//
}

template<typename T>
/*
1-de allocate original dynamic memory
2-get the dynamic memory from v1
3-get the size from v1
4-set v1.elements to nullptr
5-v1.size to 0
6-return a self reference
*/
Vector<T>& Vector<T>::operator=(Vector<T>&& v)//v1 is already in memory
{   
    if(this == &v)//this prevents the same class being copied to itself
    {
        return *this;
    }
    delete[] elements;//This would delete the original memory(v1)
    elements = v.elements; //This transfers memory from the v to v1
    size = v.size;
    v.elements = nullptr;
    v.size = 0;

    return *this;//Returns v1
}

/*
1-New allocation must be greater than space
2-Create temporary dynamic memory of size new allocation
3-Copy values from old memory array to temp array
4-Delete old memory
5-Set elements to temporary dynamic memory
6-set space to new allocation values
*/

//resize makes the extra memory available
//reserve is for later use; like when we call pushback and there isn't enough memory
template<typename T>
void Vector<T>::Reserve(size_t new_allocation)
{
    if(new_allocation <= space)
    {
        return; //This ends execution of the function immediately
    }

    int*temp = new int[new_allocation];

    for(size_t i =0; i<size; ++i)
    {
        temp[i] = elements[i];
    }

    delete[] elements;

    elements = temp;

    space = new_allocation;
}

/*
1-Reserve new allocation space
2-Initialize element values beyond the size value to 0
3-Set size to new_allocation
*/
template<typename T>
void Vector<T>::Resize(size_t new_allocation)//Used when size and space are same
{
    Reserve(new_allocation);

    for(size_t i =size; i < new_allocation; ++i)
    {
        elements[i] = 0;
    }

    size = new_allocation;
}

/*
1-if space 0 call reserve with reserve default size
2-else if size equals space resize to space * reserve default multiplier
3-set element at current size to value
4-Increment size by 1
*/
template<typename T>
void Vector<T>::PushBack(T value)
{
    if(space == 0)//Space is going to be equal to 0 if we pass 0
    {
        Reserve(RESERVE_DEFAULT_SIZE);
    }

    else if(size == space)
    {
        Resize(space * RESERVE_DEFAULT_MULTIPLIER);
    }

    elements[size] = value;
    ++size;
}
template<typename T>
Vector<T>::~Vector()
{   
    std::cout<<"\nrelease memory";
    delete[] elements;
}


template class Vector<int>;
template class Vector<double>;


//NOT PART OF THE VECTOR CLASS!!!
void use_stack_vector()
{
    Vector<int> v1(3);//delete will be automatically called - No memory leak
}

void use_heap_vector()
{
    Vector<int> *v1 = new Vector<int>(3);//Creates dynamic memory

    //delete memory here - Call the destructor here
    delete v1;
    v1 = nullptr;
}

/*Vector get_vector()
{   
    //This passes by value
    Vector<int> v1(3);
    return v1;
}*/