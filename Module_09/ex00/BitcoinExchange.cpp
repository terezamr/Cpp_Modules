#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string str) : input(str) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : mp(src.mp) , input(src.input) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
    {
        this->mp = src.mp;
        this->input = src.input;
    }
    return *this;
}

float   ft_stof(std::string str)
{
    int f = 0;
    int m = 0;
    float i = 0;
    int d = 1;
    
    if (str[f] == '-')
        throw(std::invalid_argument("Error: negative number"));
    if (str[f] == '+')  
        f++;
    while (str[f])
    {
        if (str[f] >= '0' && str[f] <= '9')
            i = i * 10 + (str[f] - '0');
        else if (str[f] == '.')
        {
            f++;
            if (!str[f] || !isdigit(str[f]))
                throw(std::invalid_argument("Error: invalid rate => " + str));
            while (str[f] && str[f] >= '0' && str[f] <= '9')
            {
                if (str[f] == '.')
                    throw(std::invalid_argument("Error: invalid rate => " + str));
                m = m * 10 + (str[f] - '0');
                d *= 10;
                f++;
            }
            continue ;
        }
        f++;
    }
    float final = (i + static_cast<float>(m)/d);
    return (final);
}

std::pair<std::string,std::string> split(std::string str, char c)
{
    std::size_t found = str.find(c);
    std::string s1 = str.substr(0, found);
    std::string s2 = str.substr(found + 1);
    
    return std::make_pair(s1, s2);
}

int    BitcoinExchange::populate(std::string str)
{
    std::ifstream   f;
    f.open(str.c_str(), std::ios::in);
    if (!f)
        return 0;
    
    std::string aux;
    getline(f, aux);
    while (getline(f, aux))
        this->mp.insert(split(aux, ','));
    std::map<std::string, std::string>::iterator it;

    f.close();
    return 1;
}

float    check_rate(std::string str)
{
    std::string s;
    int dig = 0;
    int i = 0;
    if (str[i] == '-' || str[i] == '+') {
        i++;
        dig++;
    }
    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            throw(std::invalid_argument("Error: invalid rate => " + str));
        i++;
        dig++;
    }
    s = str.substr(i - dig, dig);
    float f = ft_stof(s);
    if (f > 1000)
        throw(std::invalid_argument("Error: too large => " + s));
    return f;
}

// checks number of digits and if all chars are digits
int check_number(std::string s, int opt)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        i++;
    }
    if (i != opt)
        return 0;
    return 1;
}

// checks if the date exists
int check_ymd(std::string y, std::string m, std::string d)
{
    if (!y[0] || !m[0] || !d[0])
        return 0;

    if (!check_number(y, 4) || !check_number(m, 2) || !check_number(d, 2))
        return 0;

    int y1 = static_cast<int>(ft_stof(y));
    int m1 = static_cast<int>(ft_stof(m));
    int d1 = static_cast<int>(ft_stof(d));

    int dd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y1 % 4 == 0)
        dd[1] = 29;

    if (m1 < 1 || m1 > 12 || d1 < 1 || d1 > dd[m1 - 1])
        return 0;
    return 1;
}

void    check_dates(std::string s1)
{
    size_t pos = s1.find('-');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input => " + s1));

    pos = s1.substr(pos + 1).find('-');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input => " + s1));

    std::string aux = split(s1, '-').second;

    std::string y = split(s1, '-').first;
    std::string m = split(aux, '-').first;
    std::string d = split(aux, '-').second;

    if (!check_ymd(y, m, d))
        throw(std::invalid_argument("Error: invalid input => " + s1));

    if (s1 < "2009-01-02")
        throw(std::invalid_argument("Error: invalid input => " + s1));
}

// trims whitespaces and checks the necessary spaces (before and after '|')
std::string ft_trim(std::string str, int opt)
{
    std::string final;
    size_t start = str.find_first_not_of(" \t\v\f\r");
    size_t end = str.find_last_not_of(" \t\v\f\r");

    if (start == std::string::npos)
        throw(std::invalid_argument("Error: empty field"));
    if (opt == 1 && start != 0)
        throw(std::invalid_argument("Error: invalid input"));
    if (opt == 1 && end + 1 == str.size())
        throw(std::invalid_argument("Error: invalid input"));
    if (opt == 2 && start == 0)
        throw(std::invalid_argument("Error: invalid input"));

    final = str.substr(start, end - start + 1);
    return final;
}

int isWS(std::string s)
{
    int i = 0;
    while (s[i])
    {
        if (!std::isspace(static_cast<unsigned char>(s[i])))
            return 0;
        i++;
    }
    return 1;
}

std::pair<std::string, float> check_line(std::string str)
{
    if (str.empty() || isWS(str))
        throw(std::invalid_argument("Error: empty line"));

    size_t pos = str.find('|');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input => " + str));

    std::string s1 = ft_trim(str.substr(0, pos), 1);
    std::string s2 = ft_trim(str.substr(pos + 1, str.size()), 2);

    if (!s2[0])
        throw(std::invalid_argument("Error: invalid input"));

    check_dates(s1);
    float f = check_rate(s2);
    return std::pair<std::string, float>(s1, f);
}

float  BitcoinExchange::find_date(std::string date)
{
    std::map<std::string, std::string>::iterator it = this->mp.begin();
    while (it != mp.end() && it->first <= date)
        it++;
    it--;
    return (ft_stof(it->second));
}

#include <bits/stdc++.h>

bool isPt(int i)
{ 
    if (isprint(i))
        return 1;
    return 0;
}

int BitcoinExchange::check_f(std::ifstream f)
{
    if (f.peek() ==  std::ifstream::traits_type::eof()) {
        std::cout << "Error: empty file" << std::endl;
        f.close();
        return 0;
    }
    return 1;
}

void    BitcoinExchange::showValues(void)
{
    std::string str = "data.csv";
    if (!this->populate(str))
    {
        std::cout << "Error: could not open database '" << str << "'" << std::endl;
        return ;
    }

    // check that files exists and is not empty
    std::ifstream   f;
    f.open(this->input.c_str(), std::ios::in);
    if (!f) {
        std::cout << "Error: could not open file '" << this->input.c_str() << "'" << std::endl;
        return ;
    }
    if (f.peek() ==  std::ifstream::traits_type::eof()) {
        std::cout << "Error: empty file" << std::endl;
        f.close();
        return ;
    }

    // opens the file again, to check the first line
    std::ifstream   f0;
    f0.open(this->input.c_str(), std::ios::in);
    if (!f0) {
        std::cout << "Error: could not open file '" << this->input.c_str() << "'" << std::endl;
        return ;
    }
    
    // if the 1st line is 'date | value' it goes to the next
    // if not, starts checking each line 
    std::string aux;
    std::string tmp;
    std::getline(f0, tmp);
	if (tmp == "date | value")
		std::getline(f, aux);

    while (getline(f, aux)) {
        try {
            std::pair<std::string, float> pr = check_line(aux);
            std::cout << pr.first << " => " << pr.second;
            float closest_value = this->find_date(pr.first);
            std::cout << " = " << closest_value * pr.second << std::endl;
        }
        catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    f.close();
}
