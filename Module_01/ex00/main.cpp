#include "Zombie.hpp"

int	main(void)
{
	// new and delete allocate and deallocate the memory (dynamically)
	std::string input = "heap";
	Zombie* z1 = newZombie(input);
	z1->announce();
	delete z1;

	// allocation and de-allocation are automatically done
	// temporary memory allocation
	std::string input2 = "stack";
	randomChump(input2);
}
