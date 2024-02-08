
#include "Form.hpp"

int main()
{
    std::cout << "------------" << std::endl;
    Form f1("f1", 20, 2);
    std::cout << f1 << std::endl;

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
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }
    a.signForm(f1.getName(), f1.getSignGrade());
    std::cout << std::endl;

    try
    {
        f1.beSigned(b);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }
    b.signForm(f1.getName(), f1.getSignGrade());
    std::cout << "------------" << std::endl;
    return (0);
}
