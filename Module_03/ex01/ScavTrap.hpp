#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string str);
    	~ScavTrap();
		ScavTrap(const ScavTrap& src);

		void	guardGate();
		void	attack(const std::string &target);
		
		ScavTrap& operator=(const ScavTrap& src);	
};

#endif