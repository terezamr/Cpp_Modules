#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& src);
		Cat& operator=(const Cat& src);
};
#endif