#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           execute_grade;
    public:
        Form(const std::string str, const int g1, const int g2);
        const std::string   getName();
        bool                getSign();
        const int           getSignGrade();
        const int           getExecuteGrade();

        void                GradeTooLowException();
        void                GradeTooHighException();

        void                beSigned(Bureaucrat b);
};

std::ostream & operator<<(std::ostream & o, Form f);

#endif