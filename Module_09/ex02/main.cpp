#include "PmergeMe.hpp"

// nmr impar de numeros
// numeros iguais
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::string str = argv[1];
    // check str: not empty, only numbers, etc

    // assuming correct str
    PmergeMe obj(str);

   
    return 0;
}
