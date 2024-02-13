#include "Serializer.hpp"

Serializer::Serializer(void)
{
    //std::cout << "Serializer created." << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
    //std::cout << "Copy assigment." << std::endl;
}
Serializer::~Serializer()
{
    //std::cout << "Serializer destroyed." << std::endl;
}

Serializer& Serializer::operator=(const Serializer& src)
{
    return *this;
}

// uintptr_t an integer type which is capable of holding
// an unsigned integer value that is the size of a pointer
// convert pointers to integers and vice versa

uintptr_t    Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*    Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
