#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string str, int number) : name(str), grade (number)
{
    //std::cout << "Bureaucrat created." << std::endl;
    if (number < 1)
        throw(GradeTooHighException());
    else if (number > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
    //std::cout << "Copy assigment." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    //std::cout << "Bureaucrat destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        this->grade = rhs.grade;
    return *this;
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
    if (this->grade - 1 >= 1)
        this->grade -= 1;
    else
        throw(GradeTooHighException());
}

void    Bureaucrat::decrementGrade()
{
    if (this->grade + 1 <= 150)
        this->grade += 1;
    else
        throw(GradeTooLowException());
}

void    Bureaucrat::signForm(const std::string str, const int sg)
{
    if (this->grade <= sg)
        std::cout << this->getName() << " signed " << str << std::endl;
    else
        std::cout << this->getName() << " couldnt sign " << str << " because the grade was too low." << std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat b) {
   std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
   return o;
}