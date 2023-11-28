#include "FragTrap.hpp"

// take damage nao estao a funcionar, verificar se e preciso
int main()
{
	FragTrap a("maria");
	FragTrap b("joao");

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
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.attack("joao");
	b.takeDamage(a.getAttackDamage());
	a.highFivesGuys();
}