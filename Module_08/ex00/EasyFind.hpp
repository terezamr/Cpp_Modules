#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <ostream>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

class NotFound : public std::exception
{
public:
    virtual const char* what() const throw() {return "Not found.";}
};

template <typename T>
void    easyfind(T t, int b)
{
    if (std::find(t.begin(), t.end(), b) == t.end())
        throw(NotFound());
    std::cout << b << std::endl;
}

#endif