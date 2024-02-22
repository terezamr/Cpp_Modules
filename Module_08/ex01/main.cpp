#include "Span.hpp"

// check se o span e entre consecutivos ou a menor diferenca
// mesmo para o longest

int main(void)
{
    Span a(3);
    try
    {
        a.addNumber(5);
        a.addNumber(10);
        a.addNumber(-18);
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
        std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        a.addNumber(1);
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    Span b(4);
    try
    {
        b.addNumber(6);
        b.addNumber(11);
        b.addNumber(1);
        b.addNumber(10);
        std::cout << "Longest span: " << b.longestSpan() << std::endl;
        std::cout << "Shortest span: " << b.shortestSpan() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    Span c(10000);
    try
    {
        c.addNumbers(10);
        c.addNumbers(10000);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    return (0);
}
