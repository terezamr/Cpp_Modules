#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain*  br;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& src);
		Cat& operator=(const Cat& src);

        std::string getType() const;
        void makeSound() const;
};

#endif