#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bits/stdc++.h> 

class NotValid : public std::exception
{
public:
    virtual const char* what() const throw() {return "Out of bounds.";}
};

class Span
{
    private:
        unsigned int        N;
        unsigned int        used;
        std::vector <int>   vec;
    public:
        Span(unsigned int n);
        void    addNumber(int a);
        int     longestSpan();
        int     shortestSpan();
        void    addNumbers(unsigned int a);
};

#endif