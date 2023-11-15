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
		Zombie();
    	~Zombie();
		void		setName(std::string str);
		void		announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif