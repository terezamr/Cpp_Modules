#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Aanimal x;

    Aanimal* a;
    a = new Dog;
    a->makeSound();
    delete a;
    std::cout << std::endl;


    Aanimal* b;
    b = new Cat;
    b->makeSound();
    delete b;
    std::cout << std::endl;

}
