#include "Span.hpp"

// a.addNumber(2147483649);

int main(void)
{
    Span a(4);
    try
    {
        a.addNumber(21);
        a.addNumber(1);
        a.addNumber(11);
        a.addNumber(-21);
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
        std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        a.addNumber(4);
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

    std::cout << "-------------" << std::endl;

    Span d(a);
    std::cout << "Longest span: " << a.longestSpan() << std::endl;
    std::cout << "Shortest span: " << a.shortestSpan() << std::endl;

    Span e;
    e = b;
    std::cout << "Longest span: " << e.longestSpan() << std::endl;
    std::cout << "Shortest span: " << e.shortestSpan() << std::endl;
    return (0);
}
