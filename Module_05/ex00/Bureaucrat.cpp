#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string str, int number) : name(str)
{
    std::cout << "Bureaucrat created." << std::endl;
    try
    {
        if (number >= 1 && number <= 150)
            this->grade = number;
        else
            throw(number);
    }
    catch(int nb)
    {
        if (nb < 1)
            Bureaucrat::GradeTooLowException();
        if (nb > 150)
            Bureaucrat::GradeTooHighException();
    }
    
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat was destroyed." << std::endl;
}

const std::string   Bureaucrat::getName()
{
    return (this->name);
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

void    Bureaucrat::incrementGrade()
{
    try
    {
        if (this->grade - 1 >= 1)
            this->grade -= 1;
        else
            throw(this->grade - 1);
    }
    catch(int nb)
    {
        Bureaucrat::GradeTooLowException();
    }
}

void    Bureaucrat::decrementGrade()
{
    try
    {
        if (this->grade + 1 <= 150)
            this->grade += 1;
        else
            throw(this->grade + 1);
    }
    catch(int nb)
    {
        Bureaucrat::GradeTooHighException();
    }
}

void    Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade too low" << std::endl;
}

void    Bureaucrat::GradeTooHighException()
{
    std::cout << "Grade too high" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat b) {
   std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
   return o;
}
