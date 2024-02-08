#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "------------" << std::endl;
    PresidentialPardonForm  f1("home");
    Bureaucrat              a("A", 5);
    Bureaucrat              b("B", 100);
    try
    {
        f1.execute(b);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    b.executeForm(f1);
    std::cout << "------------" << std::endl;

    f1.beSigned(a);
    try
    {
        f1.execute(a);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    a.executeForm(f1);
    std::cout << "------------" << std::endl;

    try
    {
        f1.execute(b);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    b.executeForm(f1);
    std::cout << "------------" << std::endl;

    RobotomyRequestForm  f3("car");
    f3.beSigned(a);
    try
    {
        f3.execute(b);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    b.executeForm(f3);
    std::cout << "------------" << std::endl;

    try
    {
        f3.execute(a);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    a.executeForm(f3);
    std::cout << "------------" << std::endl;

    ShrubberyCreationForm f4("boat");
    f4.beSigned(a);
    try
    {
        f4.execute(a);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    a.executeForm(f4);
    std::cout << "------------" << std::endl;

    Bureaucrat c("C", 140);
    try
    {
        f4.execute(c);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    c.executeForm(f4);
    std::cout << "------------" << std::endl;
    return (0);
}
