#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

class ClapTrap {
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
	public:
		ClapTrap(std::string str);
    	~ClapTrap();
		ClapTrap(const ClapTrap& src);

		std::string	getName();
		int		getHitPoints();
		int		getEnergyPoints();
		int		getAttackDamage();
		void	setHitPoints(int nb);
		void	setEnergyPoints(int nb);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		
		ClapTrap& operator=(const ClapTrap& src);	
};

#endif