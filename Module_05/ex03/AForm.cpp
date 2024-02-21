#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string str, const int sg, const int eg, const std::string target) : name(str), sign_grade(sg), execute_grade(eg), target(target)
{
    //std::cout << "AForm created." << std::endl;
    if (sg < 1 || eg < 1)
        throw(GradeTooHighException());
    else if (sg > 150 || eg > 150)
        throw(GradeTooLowException());
    this->sign = 0; 
}
 
AForm::AForm(const AForm& src) : name(src.name), sign_grade(src.sign_grade), execute_grade(src.execute_grade), target(src.target)
{
    //std::cout << "Copy assigment." << std::endl;
}

AForm::~AForm()
{
    //std::cout << "AForm destroyed." << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        this->sign = rhs.sign;
    return *this;
}

const std::string   AForm::getName() const
{
    return (this->name);
}

bool    AForm::getSign() const
{
    return (this->sign);
}

int AForm::getSignGrade() const
{
    return (this->sign_grade);
}

int AForm::getExecuteGrade() const
{
    return (this->execute_grade);
}

void    AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= this->sign_grade)
        this->sign = 1;
    else
        throw(GradeTooLowException());
}

std::ostream & operator<<(std::ostream & o, AForm &f) {
   std::cout << "Form name: " << f.getName();
   std::cout << "\nsigned: " << f.getSign();
   std::cout << "\nsign grade: " << f.getSignGrade();
   std::cout << "\nexecute grade: " << f.getExecuteGrade() << std::endl;
   return o;
}

void    AForm::check_execution(Bureaucrat const & executor) const
{
    if (!this->getSign())
        throw(AForm::FormNotSigned());
    if (executor.getGrade() > this->getExecuteGrade())
        throw(AForm::GradeTooLowException());
}
