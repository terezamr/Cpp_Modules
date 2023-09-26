#include "Zombie.hpp"

int	main(void)
{
	std::string input;
	std::cout << "Enter name of the zombies:" << std::endl;
	std::cin >> input;
	Zombie* z1 = zombieHorde(3, input);
	for (int i = 0; i < 3; i++)
		z1[i].announce();
	delete [] z1;
}
