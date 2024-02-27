#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <list>
#include <limits>

template <typename T>
int easyfind(T t, int b)
{
    typename T::iterator it = std::find(t.begin(), t.end(), b);
    if (it == t.end())
        throw(std::exception());
    return *it;
}

#endif