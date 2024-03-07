#include "PmergeMe.hpp"

// nmr impar de numeros
// numeros iguais

// '4' '3 5 3'
// 4
// 'a 4' '3a
// b 3
// '' 3
// empty

int main(int argc, char **argv)
{
    {
        if (argc == 1)
        {
            std::cout << "Bad input" << std::endl;
            return 1;
        }
        try
        {
            time_t start, end;
            time(&start);
            PmergeMe obj(argv);
            time(&end);

            std::cout << "VECTOR\n";
            std::cout << "After:  ";
            obj.print_v();
            std::cout << "Time to process with vector: " << obj.getTime() << std::setprecision(20) << " ns." << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {

    }

    // std::string str = argv[1];
    // PmergeMe obj(str);

    // assuming correct str

    return 0;
}
