#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &w)
{
    this->name = str;
    this->wp = &w;
}

HumanA::~HumanA()
{
}

std::string HumanA::getName(void)
{
    return (this->name);
}

void    HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with their " << this->wp->getType() << std::endl;
}
