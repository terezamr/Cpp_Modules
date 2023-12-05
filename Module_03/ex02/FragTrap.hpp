#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string str);
		FragTrap(const FragTrap& src);
    	~FragTrap();
		FragTrap&	operator=(const FragTrap& src);

		void	highFivesGuys();
};

#endif