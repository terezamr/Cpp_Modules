#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->br = new Brain;
    std::cout << "Dog was created." << std::endl;
}

Dog::~Dog()
{
    delete this->br;
    std::cout << "Dog was destroyed." << std::endl;
}

Dog::Dog(const Dog& src)
{
    this->type = src.type;
    this->br = new Brain(*src.br);
    std::cout << "Dog copied." << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    if (this != &src)
    {
        this->type = src.type;
        delete this->br;
        this->br = new Brain(*src.br);
    }
    std::cout << "Dog copied assigment." << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}
