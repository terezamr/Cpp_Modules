#include "ScavTrap.hpp"

//take damage n esta a funcionar, ver se e preciso
int main()
{
	ScavTrap a("maria");
	ScavTrap b("joao");

	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.guardGate();
}