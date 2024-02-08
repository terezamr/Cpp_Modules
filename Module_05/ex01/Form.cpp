#include "Form.hpp"

Form::Form(const std::string str, const int sg, const int eg) : name(str), sign_grade(sg), execute_grade(eg)
{
    //std::cout << "Form created." << std::endl;
    if (sg < 1 || eg < 1)
        throw(GradeTooHighException());
    else if (sg > 150 || eg > 150)
        throw(GradeTooLowException());
    this->sign = 0; 
}

Form::Form(const Form& src) : name(src.name), sign_grade(src.sign_grade), execute_grade(src.execute_grade)
{
    //std::cout << "Copy assigment." << std::endl;
}

Form::~Form()
{
    //std::cout << "Form destroyed." << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        this->sign = rhs.sign;
    return *this;
}

const std::string   Form::getName()
{
    return (this->name);
}

bool    Form::getSign()
{
    return (this->sign);
}

const int Form::getSignGrade()
{
    return (this->sign_grade);
}

const int Form::getExecuteGrade()
{
    return (this->execute_grade);
}

void    Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= this->sign_grade)
        this->sign = 1;
    else
        throw(GradeTooLowException());
}

std::ostream & operator<<(std::ostream & o, Form &f) {
   std::cout << "Form name: " << f.getName();
   std::cout << "\nsigned: " << f.getSign();
   std::cout << "\nsign grade: " << f.getSignGrade();
   std::cout << "\nexecute grade: " << f.getExecuteGrade() << std::endl;
   return o;
}
