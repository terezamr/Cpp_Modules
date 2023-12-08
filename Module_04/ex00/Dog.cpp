#include "Dog.cpp"

Dog::Dog()
{
    std::cout << "Dog was created." << std::cout;
}

Dog::~Dog()
{
    std::cout << "Dog was destroyed." << std::cout;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Dog copied." << std::cout;
    *this = src;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog copied assigment." << std::cout;
    if (*this != src)
        this->type = src.type;
    return (*this);
}
