#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal was created." << std::endl;
    this->type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal was destroyed." << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copied." << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal& src)
{
    std::cout << "Animal copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

std::string Animal::getType() const
{
    return this->type;
}

void    Animal::makeSound() const
{
    std::cout << "animal sound" << std::endl;
}
