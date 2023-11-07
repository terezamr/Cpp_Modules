#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "ClapTrap.hpp"

class ScavTrap {
	private:
		
	public:
		ScavTrap(std::string str);
    	~ScavTrap();
		ScavTrap(const ScavTrap& src);

		void	guardGate();
		
		ScavTrap& operator=(const ScavTrap& src);	
};

#endif