#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Weapon {
	private:
		std::string	type;
	public:
		Weapon(std::string type);
    	~Weapon();
		const std::string	getType(void);
		void                setType(std::string t);
		
};

#endif