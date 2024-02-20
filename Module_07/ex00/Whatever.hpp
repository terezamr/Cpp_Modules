#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <ostream>
#include <iostream>

template <typename T>
void    swap(T& a, T& b)
{
    T aux;
    aux = a;
    a = b;
    b = aux;
}

template <typename T>
T max(T& a, T& b)
{
    if (a > b)
        return a;
    return b;
}

template <typename T>
T min(T& a, T& b)
{
    if (a < b)
        return a;
    return b;
}

// evaluation sheet
// class Awesome
// {
//     private:
//         int _n;
//     public:
//         Awesome(void): _n(0){}
//         Awesome(int n): _n(n){}
//         Awesome & operator= (Awesome &a) {_n=a._n; return *this;}
//         int get_n() const {return _n;}

//         bool operator==(Awesome const &rhs) const { return (this->_n==rhs._n);}
//         bool operator!=(Awesome const &rhs) const { return (this->_n!=rhs._n);}
//         bool operator>(Awesome const &rhs) const { return (this->_n>rhs._n);}
//         bool operator<(Awesome const &rhs) const { return (this->_n<rhs._n);}
//         bool operator>=(Awesome const &rhs) const { return (this->_n>=rhs._n);}
//         bool operator<=(Awesome const &rhs) const { return (this->_n<=rhs._n);}
// };

// std::ostream &operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o;}

#endif