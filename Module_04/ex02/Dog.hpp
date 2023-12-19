#ifndef DOG_HPP
#define DOG_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal
{
    private:
        Brain*  br;
    public:
        Dog();
        ~Dog();
        Dog(const Dog& src);
		Dog& operator=(const Dog& src);

        std::string getType() const;
        void makeSound() const;
};

#endif