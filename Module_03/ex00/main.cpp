#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("tinta");
	ClapTrap b("pepi");
	a.attack("pepi");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);
	a.attack("pepi");
	b.takeDamage(a.getAttackDamage());
	a.attack("pepi");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);
}