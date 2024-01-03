#ifndef CAT_HPP
#define CAT_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public Aanimal
{
    private:
        Brain*  br;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat& src);
		Cat& operator=(const Cat& src);

        std::string getType() const;
        void makeSound() const;
};

#endif