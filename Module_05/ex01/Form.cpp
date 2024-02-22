#include "Form.hpp"

Form::Form(const std::string str, const int sg, const int eg) : name(str), sign(false), sign_grade(sg), execute_grade(eg)
{
    //std::cout << "Form created." << std::endl;
    if (sg < 1 || eg < 1)
        throw(GradeTooHighException());
    else if (sg > 150 || eg > 150)
        throw(GradeTooLowException());
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

std::string   Form::getName() const
{
    return (this->name);
}

bool   Form::getSign() const
{
    return (this->sign);
}

int Form::getSignGrade() const
{
    return (this->sign_grade);
}

int Form::getExecuteGrade() const
{
    return (this->execute_grade);
}

void    Form::beSigned(Bureaucrat b)
{
    b.signForm(this->getName(), this->getSignGrade());
    if (b.getGrade() <= this->sign_grade)
        this->sign = 1;
    else
        throw(GradeTooLowException());
}

std::ostream & operator<<(std::ostream & o,  Form const &f) {
   std::cout << "Form name: " << f.getName();
   std::cout << "\nsigned: " << f.getSign();
   std::cout << "\nsign grade: " << f.getSignGrade();
   std::cout << "\nexecute grade: " << f.getExecuteGrade() << std::endl;
   return o;
}
