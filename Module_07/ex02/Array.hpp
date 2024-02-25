#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
	

template <typename T>
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

        T &operator [](unsigned int n) const;

        int size();

        class NotValid : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Not valid.";}
        };
};

#include "Array.tpp"

#endif