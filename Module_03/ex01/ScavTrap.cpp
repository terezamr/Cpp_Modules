#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default created." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	std::cout << "ScavTrap " << str << " created." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap()
{
	*this = src;
	std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->energyPoints = src.energyPoints;
		this->attackDamage = src.attackDamage;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is in gate keeper mode."<< std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left." <<std::endl;
		return;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no hit points left." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage! " << std::endl;
	this->energyPoints -= 1;
}
