#include "ClapTrap.hpp"

int main()
{
	ClapTrap c;
	ClapTrap a("a");
	ClapTrap b("b");
	std::cout << "\n";

	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);
	std::cout << "\n";
}