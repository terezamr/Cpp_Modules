#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat was created." << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat was destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
    std::cout << "WrongCat copied." << std::endl;
    this->type = src.type;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
    std::cout << "WrongCat copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "wrong miau" << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}
