#include "Zombie.hpp"

// It creates a zombie, name it, and return it so you can use it outside of the function
// scope.
Zombie* newZombie(std::string name)
{
	Zombie	*z;
	z = new Zombie(name);
	return (z);
}
