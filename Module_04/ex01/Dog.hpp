#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  br;
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog& src);
		Dog& operator=(const Dog& src);

        std::string getType() const;
        void makeSound() const;
};

#endif