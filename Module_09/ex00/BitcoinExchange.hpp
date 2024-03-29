#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string.h>
#include <climits>
#include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, std::string>  mp;
        std::string                         input;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string str);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&src);
        BitcoinExchange&    operator=(const BitcoinExchange& src);

        int             populate(std::string str);
        void            showValues(void);
        float           find_date(std::string date);
        int             check_f(std::ifstream f);
};

#endif
