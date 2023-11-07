#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
{
	std::cout << "Default constructor called" << std::endl;
	this->name = str;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

int	ClapTrap::getHitPoints()
{
	return (this->hitPoints);
}

int	ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}

int	ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}

std::string	ClapTrap::getName()
{
	return (this->name);
}

void	ClapTrap::setHitPoints(int nb)
{
	this->hitPoints = nb;
}

void	ClapTrap::setEnergyPoints(int nb)
{
	this->energyPoints = nb;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << "No energy left" <<std::endl;
		return;
	}
	std::cout << "Claptrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! " << std::endl;
	
	this->setEnergyPoints(getEnergyPoints() - 1);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << "No energy left" <<std::endl;
		return;
	}
	this->setHitPoints(getHitPoints() + amount);
	this->setEnergyPoints(getEnergyPoints() - 1);

	std::cout << "Claptrap " << this->getName() << " repaired itself, and now has " << this->getHitPoints() << " Hit Points! " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getEnergyPoints() == 0 || this->getHitPoints() == 0)
	{
		std::cout << "No energy left" <<std::endl;
		return;
	}
	this->setHitPoints(getHitPoints() - amount);

	std::cout << "Claptrap " << this->getName() << " was attacked, and now has " << this->getHitPoints() << " hit points! " << std::endl;
}