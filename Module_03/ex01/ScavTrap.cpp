#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string str)
{
	std::cout << "Scav Default constructor called" << std::endl;
	ClapTrap a(str);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
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
	std::cout << "ScavTrap is in Gate keeper mode. " << std::endl;
}
