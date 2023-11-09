#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	this->setName(str);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Scav "<< this->getName() << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav " << this->getName() << " Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "Scav Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Scav Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "Scav " << this->getName() << " is in Gate keeper mode. " << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " has no energy left" <<std::endl;
		return;
	}
	std::cout << "Scav " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! " << std::endl;
	
	this->setEnergyPoints(getEnergyPoints() - 1);
}
