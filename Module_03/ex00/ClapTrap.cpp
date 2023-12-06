#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default created." << std::endl;
	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string str)
{
	std::cout << "ClapTrap " << str << " created." << std::endl;
	this->name = str;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "ClapTrap " << this->name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
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

void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "Claptrap " << this->getName() << " has no energy points left." << std::endl;
		return;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << "Claptrap " << this->getName() << " has no hit points left." << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! " << std::endl;
	this->setEnergyPoints(getEnergyPoints() - 1);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "Claptrap " << this->getName() << " has no energy points left." <<std::endl;
		return;
	}
	this->setHitPoints(getHitPoints() + amount);
	this->setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "Claptrap " << this->getName() << " repaired itself and gained " << amount << " Hit Points! " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "Claptrap " << this->getName() << " has no hit points left." <<std::endl;
		return;
	}
	this->setHitPoints(getHitPoints() - amount);
	std::cout << "Claptrap " << this->getName() << " was attacked, and lost " << amount << " hit points! " << std::endl;
}
