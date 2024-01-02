#include "Brain.hpp"
#include <string.h>

Brain::Brain()
{
    std::cout << "Brain was created." << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "idea";
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed." << std::endl;
}

Brain::Brain(const Brain& src)
{
    *this = src;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copied." << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brain copied assigment." << std::endl;
    return (*this);
}
