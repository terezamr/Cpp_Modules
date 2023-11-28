#include "FragTrap.hpp"

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
	this->setName(str);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "Frag "<< this->getName() << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Frag " << this->getName() << " Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "Frag Copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "Frag Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Frag " << this->getName() << " requests an high five" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " has no energy left" <<std::endl;
		return;
	}
	std::cout << "Frag " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! " << std::endl;
	this->setEnergyPoints(getEnergyPoints() - 1);
}