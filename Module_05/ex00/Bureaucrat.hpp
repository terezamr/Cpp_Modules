#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(const std::string str, int number);
        ~Bureaucrat();
        const std::string   getName();
        int                 getGrade();

        void                incrementGrade();
        void                decrementGrade();
        
        void                GradeTooLowException();
        void                GradeTooHighException();
};

std::ostream & operator<<(std::ostream & o, Bureaucrat b);

#endif