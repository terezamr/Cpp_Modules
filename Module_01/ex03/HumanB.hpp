#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class HumanB {
	private:
		std::string	name;
        Weapon*      wp;
	public:
		HumanB(std::string str);
    	~HumanB();
        std::string	getName();
		void		attack();
		void		setWeapon(Weapon &w);
};

#endif