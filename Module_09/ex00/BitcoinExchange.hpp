#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cmath>

#define INTM 2147483647

class BitcoinExchange
{
    private:
        std::map<std::string, std::string>  mp;
        std::string                         input;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string str);

        void    populate(std::string str);
        void    showValues(void);
        float    find_date(std::string date);
};

#endif
