#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Zombie {
	private:
		std::string	name;
	public:
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name);
};

#endif