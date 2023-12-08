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

int	ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no energy points left." << std::endl;
		return;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no hit points left." << std::endl;
		return;
	}
	std::cout << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage! " << std::endl;
	this->energyPoints -= 1;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no energy points left." <<std::endl;
		return;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "Claptrap " << this->name << " repaired itself and gained " << amount << " Hit Points! " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no hit points left." <<std::endl;
		return;
	}
	this->hitPoints -= amount;
	std::cout << "Claptrap " << this->name << " was attacked, and lost " << amount << " hit points! " << std::endl;
}

