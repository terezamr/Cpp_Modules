#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    //std::cout << "RobotomyRequestForm created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target)
{
    //std::cout << "Copy assigment." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << "AForm destroyed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    (void)rhs;
    return *this;
}

const std::string   RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    check_execution(executor);
    std::cout << "Some driling noises" << std::endl;
    std::cout << this->getTarget() << " has been robotomized successfully 50% of the time. " << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << "Robotomy was successful!" << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}
