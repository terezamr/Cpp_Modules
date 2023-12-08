#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& src);
		Dog& operator=(const Dog& src);
};
#endif