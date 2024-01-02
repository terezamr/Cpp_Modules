#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << std::endl << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();

    const WrongAnimal* h = new WrongCat();
    std::cout << std::endl << h->getType() << std::endl;
    h->makeSound();

    delete h;
    delete meta;
    delete i;
    delete j;
    return 0;
}
