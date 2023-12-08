#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// std::cout << "-----Clap-----" << std::endl;
	// ClapTrap c;
	// ClapTrap a("a");
	// ClapTrap b("b");
	// std::cout << "\n";
	// a.attack("b");
	// b.takeDamage(a.getAttackDamage());
	// a.attack("b");
	// b.takeDamage(a.getAttackDamage());
	// a.attack("b");
	// b.takeDamage(a.getAttackDamage());
	// b.beRepaired(2);

	// std::cout << "\n-----Scav-----" << std::endl;
	// ScavTrap d;
	// ScavTrap e("e");
	// ScavTrap f("f");
	// std::cout << "\n";

	// for (int i = 0; i <= 50; i++)
	// {
	// 	std::cout << i << std::endl;
	// 	e.attack("f");
	// 	f.takeDamage(e.getAttackDamage());
	// }
	// std::cout << "\n";
	// f.attack("e");
	// f.beRepaired(10);
	// f.attack("e");
	// std::cout << "\n\n-----Dest-----" << std::endl;

	std::cout << "\n-----Frag-----" << std::endl;
    FragTrap g("g");
	FragTrap h("h");

	for (int i = 0; i <= 100; i++)
	{
		std::cout << i << std::endl;
		g.attack("h");
		h.takeDamage(g.getAttackDamage());
	}
	std::cout << std::endl;
	h.attack("g");
    h.beRepaired(100);
	h.attack("g");
    g.highFivesGuys();

	std::cout << "\n\n-----Dest-----" << std::endl;
}
