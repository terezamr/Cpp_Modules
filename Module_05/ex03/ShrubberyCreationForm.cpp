#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137, target), target(target)
{
    //std::cout << "ShrubberyCreationForm created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target)
{
    //std::cout << "Copy assigment." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    //std::cout << "AForm destroyed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    (void)rhs;
    return *this;
}

const std::string   ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    check_execution(executor);
    std::ofstream	a;
	std::string		new_file;
	new_file = this->target+ "_shrubbery";

	a.open(new_file.c_str(), std::ios::in | std::ios::app);
	if (!a)
		std::cout << "Not able to create the file" << std::endl;

    a << "                              # #### ####             " << std::endl;
    a << "                           ###///#|### |/####         " << std::endl;
    a << "                           ##//#///||/##/_/##/_#      " << std::endl;
    a << "                         ### ///###|//// # ###        " << std::endl;
    a << "                       ##_//#///## | #/###_/_####     " << std::endl;
    a << "                      ## #### #//#| /  #### ##/##    " << std::endl;
    a << "                       __#_--###`  |{,###---###-~     " << std::endl;
    a << "                                 //}{                 " << std::endl;
    a << "                                  }}{                 " << std::endl;
    a << "                                  }}{                 " << std::endl;
    a << "                                  {{}                 " << std::endl;
    a << "                            , -=-~{ .-^- _            " << std::endl;
    a << "                                 `}                   " << std::endl;
    a << "                                   {                  " << std::endl;
    a.close();
}
