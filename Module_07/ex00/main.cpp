#include "Whatever.hpp"

template <typename T>
void    swap(T& a, T& b)
{
    T aux;
    aux = b;
    b = a;
    a = aux;
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

int main(void)
{
    int a = 2;
    int b = 10;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    swap(a, b);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "max: " << max(a, b) << std::endl;
    std::cout << "min: " << min(a, b) << std::endl;
    std::cout << "-------------" << std::endl;

    float   c = -2.4;
    float   d = -2.5;
    std::cout << "c: " << c << ", d: " << d << std::endl;
    swap(c, d);

    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "max: " << max(c, d) << std::endl;
    std::cout << "min: " << min(c, d) << std::endl;

    std::cout << "-------------" << std::endl;
    std::string e = "apple";
    std::string f = "banana";
    std::cout << "e: " << e << ", f: " << f << std::endl;
    swap(e, f);

    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "max: " << max(f, e) << std::endl;
    std::cout << "min: " << min(f, e) << std::endl;
}