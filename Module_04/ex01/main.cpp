#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int n = 6;
    Animal* list[n];
    int i = 0;
    while (i < n / 2)
    {
        list[i] = new Dog;
        i++;
    }
    std::cout << std::endl;
    while (i < n)
    {
        list[i] = new Cat;
        i++;
    }
    std::cout << std::endl;
    for (int f = 0; f < n; f++)
        delete list[f];
}
