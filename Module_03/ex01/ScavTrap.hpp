#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const ScavTrap& src);
    	~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& src);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif