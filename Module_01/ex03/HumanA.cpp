#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &w) : wp(w)
{
    this->name = str;
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
	if (this->wp.getType() != "")
    	std::cout << this->getName() << " attacks with their " << this->wp.getType() << std::endl;
	else
		std::cout << this->getName() << " attacks with their empty weapon" << std::endl;
    
}
