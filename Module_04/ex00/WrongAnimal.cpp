#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal was created." << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal was destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copied." << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void    WrongAnimal::makeSound() const
{
     std::cout << "wrong animal sound" << std::endl;
}
