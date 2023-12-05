#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string str);
		DiamondTrap(const DiamondTrap& src);
    	~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap& src);

		void	whoAmI();
		using	ScavTrap::attack;
		//using FragTrap::hitPoints;
};

#endif