#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat was created." << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat was destroyed." << std::endl;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copied." << std::endl;
    this->type = src.type;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "miau" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}
