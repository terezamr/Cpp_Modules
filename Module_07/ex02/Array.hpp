#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

/*template <typename T>
T max(T& a, T& b);*/

template <typename T>
class Array {
    private:
        unsigned int    len;
        T               *arr;
    public:
        Array(void);
        Array(unsigned int n);
};

#include "Array.tpp"

#endif