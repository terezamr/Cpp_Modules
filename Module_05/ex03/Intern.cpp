#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    //std::cout << "Intern created." << std::endl;
}

Intern::Intern(const Intern& src)
{
    //std::cout << "Copy assigment." << std::endl;
    (void)src;
}

Intern::~Intern()
{
    //std::cout << "Intern destroyed." << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return *this;
}

AForm*    Intern::createPres(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*    Intern::createRobot(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm*    Intern::createShrub(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm*    Intern::makeForm(std::string name, std::string target)
{
    // alias (different name for a data type) of a pointer for a function in the
    // intern class
    // (returns a pointer to form and has as argument a string)
    typedef AForm* (Intern::*FormFunctionPtr)(std::string);

    std::string names[] = {"presidential pardon", "robotomy request", "shruberry creation"};
    FormFunctionPtr functions[] = {&Intern::createPres, &Intern::createRobot, &Intern::createShrub};
	
    int i = 0;
    while (i < 3 && name != names[i])
        i++;
    if (i != 3)
    {
        std::cout << "Intern creates " << name << std::endl;
        return (this->*functions[i])(target);
    }
    else
        throw(NoForm());
}
