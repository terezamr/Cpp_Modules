#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->br = new Brain;
    std::cout << "Cat was created." << std::endl;
}

Cat::~Cat()
{
    delete this->br;
    std::cout << "Cat was destroyed." << std::endl;
}

Cat::Cat(const Cat& src) : Animal()
{
    this->type = src.type;
    this->br = new Brain(*src.br);
    std::cout << "Cat copied." << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    if (this != &src)
    {
        this->type = src.type;
        delete this->br;
        this->br = new Brain(*src.br);
    }
    std::cout << "Cat copied assigment." << std::endl;
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
