#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& src);

        std::string getType() const;
        void makeSound() const;
};

#endif