#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    //Animal x;

    const Animal* meta = new Animal();
    std::cout << "type: " << meta->getType() << std::endl;
    meta->makeSound();
    delete meta;
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << "type: " << i->getType() << std::endl;
    i->makeSound();
    delete i;
    std::cout << std::endl;
    
    const Animal* j = new Dog();
    std::cout << "type: " << j->getType() << std::endl;
    j->makeSound();
    delete j;
    std::cout << std::endl;

    const WrongAnimal* h = new WrongCat();
    std::cout << "type: " << h->getType() << std::endl;
    h->makeSound();
    delete h;
    std::cout << std::endl;

    // const WrongCat* c = new WrongCat();
    // c->makeSound();
    // delete c;
    // std::cout << std::endl;
    // return 0;
}
