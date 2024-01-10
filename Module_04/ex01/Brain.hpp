#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <ostream>
#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& src);
		Brain& operator=(const Brain& src);
};

#endif