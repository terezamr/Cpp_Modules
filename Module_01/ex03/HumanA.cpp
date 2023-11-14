#include "HumanA.hpp"

// inicializacao feita ao mesmo tempo da declaracao, porque a referencia tem
// sempre de se criada em relacao a uma variavel
HumanA::HumanA(std::string str, Weapon &w) : wp(w)
{
    this->name = str;
    //this->wp = &w;
}

HumanA::~HumanA()
{
}

std::string HumanA::getName(void)
{
    return (this->name);
}

void    HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with their " << this->wp.getType() << std::endl;
}
