#include "Cat.cpp"

Cat::Cat()
{
    std::cout << "Cat was created." << std::cout;
}

Cat::~Cat()
{
    std::cout << "Cat was destroyed." << std::cout;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copied." << std::cout;
    *this = src;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat copied assigment." << std::cout;
    if (*this != src)
        this->type = src.type;
    return (*this);
}
