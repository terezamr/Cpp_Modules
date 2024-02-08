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
}

Intern::~Intern()
{
    //std::cout << "Intern destroyed." << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    return *this;
}

AForm*    Intern::createPres(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*    Intern::createRobot(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*    Intern::createShrub(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*    Intern::makeForm(std::string name, std::string target)
{
    typedef AForm* (Intern::*FormFunctionPtr)(std::string);

    std::string names[] = {"presidential pardon", "robotomy request", "shruberry creation"};
    FormFunctionPtr functions[] = {&Intern::createPres, &Intern::createRobot, &Intern::createShrub};
	//AForm* (Intern::*fc[3])() = {&Intern::createPres(target), &Intern::createRobot(target), &Intern::createShrub(target)};
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