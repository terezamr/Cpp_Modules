#include "Form.hpp"

Form::Form(const std::string str, const int g1, const int g2) : name(str), sign_grade(g1), execute_grade(g2)
{
    std::cout << "Form was created." << std::endl;
    this->sign = false;
}

const std::string   Form::getName()
{
    return (this->name);
}

bool   Form::getSign()
{
    return (this->sign);
}

const int   Form::getSignGrade()
{
    return (this->sign_grade);
}

const int   Form::getExecuteGrade()
{
    return (this->execute_grade);
}

void    Form::GradeTooLowException()
{
    std::cout << "Grade too low" << std::endl;
}

void    Form::GradeTooHighException()
{
    std::cout << "Grade too high" << std::endl;
}

void    Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= this->sign_grade)
        this->sign = 1;
    else
        Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form f) {
   std::cout << "Form name: " << f.getName();
   std::cout << "; signed: " << f.getSign();
   std::cout << "; sign grade: " << f.getSignGrade();
   std::cout << "; execute grade: " << f.getExecuteGrade() << "." << std::endl;
   return o;
}