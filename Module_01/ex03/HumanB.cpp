#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
    this->name = str;
    this->wp = NULL;
}

HumanB::~HumanB()
{
}

std::string HumanB::getName(void)
{
    return (this->name);
}

void    HumanB::attack(void)
{
	if (this->wp != NULL && this->wp->getType() != "")
    	std::cout << this->getName() << " attacks with their " << this->wp->getType() << std::endl;
	else
		std::cout << this->getName() << " doesnt have a weapon to attack." << std::endl;
}

void    HumanB::setWeapon(Weapon &w)
{
    this->wp = &w;
}
