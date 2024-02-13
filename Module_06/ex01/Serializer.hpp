#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdint>

struct Data {
    std::string name;
    int         age;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &src);
    public:
        ~Serializer();
        Serializer& operator=(const Serializer& src);

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif