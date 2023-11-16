#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class HumanA {
	private:
		std::string	name;
        Weapon&		wp;
	public:
		HumanA(std::string str, Weapon &w);
    	~HumanA();
        std::string	getName();
		void		attack();
};

#endif