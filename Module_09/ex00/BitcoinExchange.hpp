#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> mp;
        std::string input;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string str);
        void    populate(std::string str);
        void    showValues(void);
};

#endif