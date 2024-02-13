#include "ScalarConverter.hpp"

// check: com caracter ? aparecer 63.0f e 63.0
// nao pode ser inicilizado nenhum objeto da classe
// check deixar construtores

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments.\n";
        return 0;
    }

    //ScalarConverter a;
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
