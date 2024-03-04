#include "BitcoinExchange.hpp"

// input 1 - database: exchange rate para cada data (dada)
// input 2 - database 2: precos/data a ser avaliados (alteravel)

// output - valor da btc para cada data (input 1 x 2)
// se a data de 2 nao existir em 1, usar a + proxima (lower)

// missing: max int + forma canonica
int check_input(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }
    std::ofstream f;
    f.open(argv[1], std::ios::in);
    if (!f)
    {
        std::cout << "Bad input" << std::endl;
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (!check_input(argc, argv))
        return 0;
    BitcoinExchange mp(argv[1]);
    mp.showValues();
    return 0;
}
