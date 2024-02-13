#include "Serializer.hpp"

// check constructors

int main(void)
{
    Data    *a = new Data;
    a->name = "maria";
    a->age = 30;

    uintptr_t b;
    b = Serializer::serialize(a);

    Data *c;
    c = Serializer::deserialize(b);

    std::cout << "Name: " << c->name << std::endl;
    std::cout << "Age: " << c->age << std::endl;

    std::cout << "Name: " << Serializer::deserialize(Serializer::serialize(a))->name << std::endl;
    std::cout << "Age: " << Serializer::deserialize(Serializer::serialize(a))->age << std::endl;
    delete a;

    return 0;
}