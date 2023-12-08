#include "Animal.cpp"

Animal::Animal()
{
    std::cout << "Animal was created." << std::cout;
}

Animal::~Animal()
{
    std::cout << "Animal was destroyed." << std::cout;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copied." << std::cout;
    *this = src;
}

Animal& Animal::operator=(const Animal& src)
{
    std::cout << "Animal copied assigment." << std::cout;
    if (*this != src)
        this->type = src.type;
    return (*this);
}

std::string Animal::getType()
{
    return this->type;
}
