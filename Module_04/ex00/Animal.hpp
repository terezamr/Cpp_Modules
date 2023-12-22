#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <ostream>
#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        ~Animal();
        Animal(const Animal& src);
		Animal& operator=(const Animal& src);

        std::string     getType() const;
        virtual void    makeSound() const;
};

#endif