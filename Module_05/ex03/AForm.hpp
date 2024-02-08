#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           execute_grade;
        const std::string   target;
    public:
        AForm(const std::string str, const int sg, const int eg, const std::string target);
        ~AForm();
        AForm(const AForm& src);
        AForm& operator=(const AForm& rhs);

        const std::string   getName() const;
        bool          getSign() const;
        int           getSignGrade() const;
        int           getExecuteGrade() const;

        void          beSigned(Bureaucrat b);
        virtual void  execute(Bureaucrat const & executor) const = 0;
        void          check_execution(Bureaucrat const & executor) const;

        // Exception Classes
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Grade too high.";}
        };
        
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Grade too low.";}
        };

        class FormNotSigned : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Form not signed.";}
        };
};

std::ostream & operator<<(std::ostream & o, AForm &f);

#endif