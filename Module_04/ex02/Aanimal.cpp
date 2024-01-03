#include "Aanimal.hpp"

Aanimal::Aanimal()
{
    std::cout << "Aanimal was created." << std::endl;
    this->type = "Aanimal";
}

Aanimal::~Aanimal()
{
    std::cout << "Aanimal was destroyed." << std::endl;
}

Aanimal::Aanimal(const Aanimal& src)
{
    std::cout << "Aanimal copied." << std::endl;
    *this = src;
}

Aanimal& Aanimal::operator=(const Aanimal& src)
{
    std::cout << "Aanimal copied assigment." << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

std::string Aanimal::getType() const
{
    return this->type;
}
