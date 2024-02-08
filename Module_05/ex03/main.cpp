#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "------------" << std::endl;    
    Intern someRandomIntern;
    AForm* a;
    AForm* b;
    AForm* c;
    a = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *a;
    std::cout << "------------" << std::endl;
    try
    {
        b = someRandomIntern.makeForm("presidential pardon", "Bender");
        c = someRandomIntern.makeForm("berry creation", "Bender");
        a = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "------------" << std::endl;

    delete a;
    delete b;
    return (0);
}
