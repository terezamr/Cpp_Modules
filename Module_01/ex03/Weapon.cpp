#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}


void	Weapon::setType(std::string t)
{
	this->type = t;
}

std::string const	Weapon::getType(void)
{
	return (this->type);
}
