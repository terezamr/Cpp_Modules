#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class AForm;

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(const std::string str, int number);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        
        std::string   getName() const;
        int           getGrade() const;

        void          incrementGrade();
        void          decrementGrade();

        void          signForm(const std::string str, const int sg);
        void          executeForm(AForm const & form);

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

std::ostream & operator<<(std::ostream & o, Bureaucrat &b);

#endif