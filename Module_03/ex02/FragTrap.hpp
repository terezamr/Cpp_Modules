#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string str);
    	~FragTrap();
		FragTrap(const FragTrap& src);

		void	highFivesGuys();
		void	attack(const std::string &target);
		
		FragTrap& operator=(const FragTrap& src);	
};

#endif