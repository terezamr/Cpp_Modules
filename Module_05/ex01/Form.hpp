#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           execute_grade;
    public:
        Form(const std::string str, const int sg, const int eg);
        ~Form();
        Form(const Form& src);
        Form& operator=(const Form& rhs);

        const std::string   getName();
        bool                getSign();
        const int           getSignGrade();
        const int           getExecuteGrade();

        void                beSigned(Bureaucrat b);

        // Exception Classes
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Grade too high";}
        };
        
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Grade too low";}
        };
};

std::ostream & operator<<(std::ostream & o, const Form &f);

#endif