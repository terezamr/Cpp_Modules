#include "Brain.hpp"
#include <string.h>

Brain::Brain()
{
    std::cout << "Brain was created." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed." << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copied." << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "Brain copied assigment." << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    return (*this);
}
