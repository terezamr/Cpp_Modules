#include "ScalarConverter.hpp"

// int check_str(char *str)
// {
//     if (!strcmp(str, "-inf") || !strcmp(str, "+inf") || !strcmp(str, "nan")
//         || !strcmp(str, "-inff") || !strcmp(str, "+inff"))
//         return (0);
//     return (1);
// }

// void    IntConverter(char *str)
// {
//     int i = 0;
//     while (str[i] >= '0' && str[i] <= '9')
//         i++;
//     std::strtol(str, nullptr, 10);
//     std::cout << str << std::endl;
// }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments.\n";
        return 0;
    }
    ScalarConverter a(argv[1]);
    a.convert();
    return 0;
}
