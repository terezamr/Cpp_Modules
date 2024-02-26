#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NotFound : public std::exception
{
    public:
        virtual const char* what() const throw() {return "Not found.";}
};

template <typename T>
int easyfind(T t, int b)
{
    typename T::iterator it = std::find(t.begin(), t.end(), b);
    if (it == t.end())
        throw(NotFound());
    return *it;
}

#endif