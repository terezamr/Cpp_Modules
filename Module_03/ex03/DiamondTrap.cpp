#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default created." << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string str)
{
	std::cout << "DiamondTrap " << str << " created." << std::endl;
	this->name = str;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	*this = src;
	std::cout << "DiamondTrap " << this->name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Who am I" << std::endl;
}
