#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    //std::cout << "PresidentialPardonForm created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target)
{
    //std::cout << "Copy assigment." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << "AForm destroyed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    (void)rhs;
    return *this;
}

const std::string   PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    check_execution(executor);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
