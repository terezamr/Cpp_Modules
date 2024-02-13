#ifndef ARRAY_TPP
#define ARRAY_TPP

//#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : len(0), arr(nullptr)
{
    std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
    std::cout << "Array constructor called" << std::endl;
    this->arr = new T[n];
}

#endif