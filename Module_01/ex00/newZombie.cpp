#include "Zombie.hpp"

// It creates a zombie, name it, and return it so you can use it outside of the function
// scope.
// quando a funcao newzobie e acabada de executar, o objeto local z (se criado na stack) e destruido
// logo o pointer para o objeto vai ter um comportamento indefinido, por isso e que se tem de alocar
// na heap
Zombie* newZombie(std::string name)
{
	Zombie	*z;
	z = new Zombie(name);
	return (z);
}
