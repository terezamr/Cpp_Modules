#ifndef ITER_HPP
#define ITER_HPP

#include <ostream>
#include <iostream>

template <typename T>
void    iter(T *a, unsigned int len, void (*func)(T const&))
{
    for (int i = 0; i < len; i++)
        func(a[i]);
}

template <typename T>
void    print_value(T a)
{
    std::cout << a << std::endl;
}

// evaluation sheet
// class Awesome 
// {
//     private:
//         int _n;
//     public:
//         Awesome(void): _n(42) { return; }
//         int get(void) const { return this->_n; }
// };

// std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o;}

// template <typename T>
// void print(T const &x)
// {
//     std::cout << x << std::endl;
//     return;
// }

#endif