#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// duvida: pode se fazer re-assign da weapon do human b para null?
int main(void)
{
	{
		//reference: cant be re-assigned, weapon never changes and is never null
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
		//pointer: can be assigned null directly. whereas a reference cannot be
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	Weapon club2 = Weapon("other");
	jim.setWeapon(club2);
	jim.attack();
	}
    return 0;
}
