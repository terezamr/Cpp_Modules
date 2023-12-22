#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    std::cout << "Dog was created." << std::endl;
    this->type = "Dog";
    this->br = new Brain;
}

Dog::~Dog()
{
    std::cout << "Dog was destroyed." << std::endl;
    delete this->br;
}

Dog::Dog(const Dog& src) : Aanimal(src)
{
    std::cout << "Dog copied." << std::endl;
    this->type = src.type;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
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
