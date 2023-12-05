#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "-----Clap-----" << std::endl;
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

	std::cout << "\n-----Scav-----" << std::endl;
	ScavTrap d;
	ScavTrap e("e");
	ScavTrap f("f");
	std::cout << "\n";
	e.attack("f");
	f.takeDamage(e.getAttackDamage());
	e.attack("f");
	f.takeDamage(e.getAttackDamage());
	e.attack("f");
	f.takeDamage(e.getAttackDamage());
	f.beRepaired(2);

	std::cout << "\n-----Frag-----" << std::endl;
    FragTrap g("g");
	FragTrap h("h");
    g.attack("h");
    h.takeDamage(g.getAttackDamage());
    h.beRepaired(100);
    g.highFivesGuys();

	std::cout << "\n\n-----Dest-----" << std::endl;
}
