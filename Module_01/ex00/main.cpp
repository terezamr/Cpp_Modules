#include "Zombie.hpp"

int	main(void)
{
	// new and delete allocate and dealllocate the memory (dynamically)
	std::string input;
	std::cout << "Enter name of the heap zombie:" << std::endl;
	std::cin >> input;
	Zombie* z1 = newZombie(input);
	z1->announce();
	delete z1;

	// allocation and de-alllocation are automatically done
	// temporary memory allocation
	std::string input2;
	std::cout << "Enter name of the stack zombie:" << std::endl;
	std::cin >> input2;
	randomChump(input2);
}
