#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bits/stdc++.h> 

class Span
{
    private:
        unsigned int        N;
        unsigned int        used;
        std::vector <int>   vec;
    public:
        Span();
        ~Span();
        Span(unsigned int n);
        Span(const Span &src);
        Span &operator=(const Span &src);

        void    addNumber(int a);
        long    longestSpan();
        long    shortestSpan();
        void    addNumbers(unsigned int a);
};

#endif