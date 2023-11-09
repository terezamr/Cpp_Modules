#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("maria");
	ScavTrap b("joao");

	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.guardGate();
}