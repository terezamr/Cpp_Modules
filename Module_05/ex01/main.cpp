#include "Form.hpp"

int main()
{
    std::cout << "------------" << std::endl;
    Form f1("f1", 20, 2);
    std::cout << f1;

    std::cout << "------------" << std::endl;
    try
    {
        Form f2("f2", 0, 26);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "------------" << std::endl;
    Bureaucrat a("A", 5);
    Bureaucrat b("B", 50);

    try
    {
        f1.beSigned(a);
        f1.beSigned(b);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }

    std::cout << "------------" << std::endl;
    std::cout << f1;
    std::cout << "------------" << std::endl;
    return (0);
}
