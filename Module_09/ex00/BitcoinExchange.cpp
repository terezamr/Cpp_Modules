#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string str) : input(str)
{
    // std::cout << "Constructor" << std::endl;
}

#include <sstream>

std::pair<std::string,std::string> split(std::string str)
{
    std::size_t found = str.find(",");
    std::string s1 = str.substr(0, found);
    std::string s2 = str.substr(found + 1);
    int f = 0;
    int m = 0;
    int i = 0;
    int d = 1;
    std::cout << "s2 " << s2 << std::endl;
    while (s2[f])
    {
        if (s2[f] >= '0' && s2[f] <= '9')
        {
            i = i * 10 + (s2[i] - '0');
        }
        if (s2[f] == '.')
        {
            f++;
            while (s2[f])
            {
                std::cout << "m " << m << std::endl;
                std::cout << "d " << d << std::endl;
                std::cout << "s2[i] " << s2[i] << std::endl;
                m = m * 10 + (s2[i] - '0');
                d *= 10;
                f++;
            }
        }
        f++;
    }
    std::cout << "m " << m << std::endl;
    //i = i + (float)m/d;
    //std::cout << i + (float)m/d << std::endl;
    return std::make_pair(s1, s2);
}

void    BitcoinExchange::populate(std::string str)
{
    std::ifstream   f;
    f.open(str.c_str(), std::ios::in);
    if (!f)
    {
        std::cout << "Can't open '" << str << "'." << std::endl;
        return ;
    }
    
    std::string aux;
    getline(f, aux);
    split("1.15");
    // while (getline(f, aux))
    //     this->mp.insert(split(aux));
    std::map<std::string, std::string>::iterator it;
    // for (it = mp.begin(); it != mp.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
    f.close();
}

int check_number(std::string str, unsigned int &i, int max, int opt)
{
    int f = 0;
    while (f < max && str[i]) {
        if (str[i] < '0' || str[i] > '9') {
            std::cout <<  "Bad number" << std::endl;
            return 0;
        }
        i++;
        f++;
    }
    if (opt == 1) {
        if (str[i] != '-') {
            std::cout <<  "Wrong format" << std::endl;
            return 0;
        }
    }
    if (opt == 2) {
        if (str[i] != ' ') {
            std::cout <<  "Wrong format" << std::endl;
            return 0;
        }
        while (i < str.size() && str[i] == ' ')
            i++;
    }
    return 1;
}
 
int check_line(std::string str)
{
    unsigned int i = 0;
    while (i < str.size() && str[i] == ' ')
        i++;
    if (!check_number(str, i, 4, 1))
        return (0);
    i++;
    if (!check_number(str, i, 2, 1))
        return (0);
    i++;
    if (!check_number(str, i, 2, 2))
        return (0);
    if (str[i] != '|') {
        std::cout <<  "Wrong format" << std::endl;
        return 0;
    }
    i++;
    if (str[i] != ' ') {
        std::cout <<  "Wrong format" << std::endl;
        return 0;
    }
    while (i < str.size() && str[i] == ' ')
        i++;
    while (str[i] && str[i] != ' ') {
        if ((str[i] < '0' || str[i] > '9')) {
            std::cout <<  "Bad rate" << std::endl;
            return 0;
        }
        i++;
    }
    while (str[i]) {
        if (str[i] != ' ') {
            std::cout <<  "Wrong format" << std::endl;
            return 0;
        }
        i++;
    }
    return 1;
}
 
void    BitcoinExchange::showValues(void)
{
    std::string str = "data.csv";
    this->populate(str);

    std::ifstream   f;
    f.open(this->input.c_str(), std::ios::in);
    std::string aux;
    getline(f, aux);
    while (getline(f, aux))
    {
        if (check_line(aux))
            std::cout << aux << std::endl;
    }
}
