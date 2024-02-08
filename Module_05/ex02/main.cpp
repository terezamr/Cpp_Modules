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
        b.executeForm(f1);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    f1.beSigned(a);
    try
    {
        a.executeForm(f1);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    try
    {
        b.executeForm(f1);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    RobotomyRequestForm  f3("car");
    f3.beSigned(a);
    try
    {
        b.executeForm(f3);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    try
    {
        a.executeForm(f3);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    ShrubberyCreationForm f4("alien");
    std::cout << f4;
    f4.beSigned(a);
    std::cout << "------------" << std::endl;
    std::cout << f4;
    try
    {
        a.executeForm(f4);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;

    Bureaucrat c("C", 140);
    try
    {
        c.executeForm(f4);
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "------------" << std::endl;
    return (0);
}
