#include "Zombie.hpp"

int	main(void)
{
	int N = 5;
	Zombie* z1 = zombieHorde(N, "bob");
	for (int i = 0; i < N; i++)
		z1[i].announce();
	delete [] z1;

	std::cout << std::endl;

	N = 2;
	Zombie* z2 = zombieHorde(N, "jim");
	for (int i = 0; i < N; i++)
		z2[i].announce();
	delete [] z2;
}
