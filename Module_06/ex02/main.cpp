#include "Base.hpp"

class A  : public Base {};
class B  : public Base {};
class C  : public Base {};

Base* generate(void)
{
    int n = std::rand() % 10;
    if (n >= 0 && n <= 3)
        return (new A);
    else if (n > 3 && n <= 6)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object is of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is of type C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Object is of type A" << std::endl;
    }
    catch(const std::exception& e) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Object is of type B" << std::endl;
    }
    catch(const std::exception& e) {}
    
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Object is of type C" << std::endl;
    }
    catch(const std::exception& e) {}
}

int main(void)
{
    Base* obj = generate();
    identify(obj);
    identify(*obj);

    std::cout << "---------------" << std::endl;

    Base* obj1 = generate();
    identify(obj1);
    identify(*obj1);

    std::cout << "---------------" << std::endl;

    Base* obj2 = generate();
    identify(obj2);
    identify(*obj2);

    std::cout << "---------------" << std::endl;

    Base* obj3 = generate();
    identify(obj3);
    identify(*obj3);

    return 0;
}