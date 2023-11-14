#include "Zombie.hpp"

// It creates a zombie, name it, and the zombie announces itself.
// could also be allocated in heap with new
void randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}
