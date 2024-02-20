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
        a.addNumber(1);
        std::cout << "Longest span: " << a.longestSpan() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    try
    {
        std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    Span b(10000);
    try
    {
        b.addNumbers(10);
        //b.addNumbers(10000);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}
