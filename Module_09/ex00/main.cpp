#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }
    BitcoinExchange mp(argv[1]);
    mp.showValues();
    return 0;
}

