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
		Zombie(std::string str);
    	~Zombie();
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif