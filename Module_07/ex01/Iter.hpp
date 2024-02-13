#ifndef ITER_HPP
#define ITER_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

template <typename T>
void    iter(T *a, int len, void (*func)(T &));

template <typename T>
void    print_value(T a);

#endif