#ifndef Aanimal_HPP
#define Aanimal_HPP

#include <ostream>
#include <iostream>
#include <string>

class Aanimal
{
    protected:
        std::string type;
        Aanimal();
    public:
        ~Aanimal();
        Aanimal(const Aanimal& src);
		Aanimal& operator=(const Aanimal& src);

        std::string getType() const;
        virtual void    makeSound() const;
};

#endif