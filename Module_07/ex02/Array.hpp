#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

/*template <typename T>
T max(T& a, T& b);*/

template <class T>
class Array {
    private:
        unsigned int    len;
        T               *arr;
    public:
        Array(void);
        Array(unsigned int n);
        T &operator [](int n);

        class IndexNotValid : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Index not valid.";}
        };
};

#include "Array.tpp"

#endif