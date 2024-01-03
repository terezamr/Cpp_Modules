#ifndef Aanimal_HPP
#define Aanimal_HPP

#include <ostream>
#include <iostream>
#include <string>

class Aanimal
{
    protected:
        Aanimal();
        std::string type;
    public:
        virtual ~Aanimal();
        Aanimal(const Aanimal& src);
		Aanimal& operator=(const Aanimal& src);

        std::string     getType() const;
        virtual void    makeSound() const;
};

#endif