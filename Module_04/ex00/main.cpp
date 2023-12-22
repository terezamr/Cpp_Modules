#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << "\n" << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();

    std::cout << "\nWrong" << std::endl;
    const WrongAnimal* h = new WrongCat();
    std::cout << h->getType() << std::endl;
    h->makeSound();

    delete h;
    delete meta;
    delete i;
    return 0;
}
