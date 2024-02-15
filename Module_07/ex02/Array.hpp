#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

template <class T>
class Array {
    private:
        unsigned int    len;
        T               *arr;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& src);
        Array&  operator=(const Array& src);

        T &operator [](int n);

        int size();

        class IndexNotValid : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Index not valid.";}
        };
};

#include "Array.tpp"

#endif