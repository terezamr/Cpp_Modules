#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& rhs);
        
        AForm*    makeForm(std::string name, std::string target);
        AForm*    createPres(std::string target);
        AForm*    createRobot(std::string target);
        AForm*    createShrub(std::string target);

        // Exception Classes
        class NoForm : public std::exception
        {
        public:
            virtual const char* what() const throw() {return "Form doesnt exist.";}
        };
};

#endif