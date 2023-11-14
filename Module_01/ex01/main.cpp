#include "Zombie.hpp"

int	main(void)
{
	std::string input;
	std::cout << "Enter the name of the zombies:" << std::endl;
	std::cin >> input;
	Zombie* z1 = zombieHorde(2, input);
	for (int i = 0; i < 2; i++)
		z1[i].announce();
	delete [] z1;
}
