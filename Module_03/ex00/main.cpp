#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("tinta");
	ClapTrap b("pepi");
	a.attack("pepi");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
}