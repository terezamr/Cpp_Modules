#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string str) : input(str)
{
    // std::cout << "Constructor" << std::endl;
}

float   ft_stoi(std::string str)
{
    int f = 0;
    int m = 0;
    float i = 0;
    int d = 1;
    int point = 0;
    
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
            point++;
            f++;
            if (!str[f] || !isdigit(str[f]) || point == 2)
                throw(std::invalid_argument("Error: invalid rate => " + str));
            while (str[f] >= '0' && str[f] <= '9')
            {
                m = m * 10 + (str[f] - '0');
                d *= 10;
                f++;
            }
        }
        f++;
    }
    float final = (i + static_cast<float>(m)/d);
    /*if (final > INT_MAX)
    {
        std::cout <<  "Error: too large number => ";
        return -1;
    }*/
    return (final);
}

std::pair<std::string,std::string> split(std::string str, char c)
{
    std::size_t found = str.find(c);
    std::string s1 = str.substr(0, found);
    std::string s2 = str.substr(found + 1);
    
    return std::make_pair(s1, s2);
}

void    BitcoinExchange::populate(std::string str)
{
    std::ifstream   f;
    f.open(str.c_str(), std::ios::in);
    if (!f)
    {
        std::cout << "Can't open '" << str << "'. ";
        throw(std:: exception());
    }
    
    std::string aux;
    getline(f, aux);
    while (getline(f, aux))
        this->mp.insert(split(aux, ','));
    std::map<std::string, std::string>::iterator it;

    // for (it = mp.begin(); it != mp.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    f.close();
}

int check_date(std::string str, int opt, int digits)
{
    float f = ft_stoi(str);
    if (opt == YEAR) {
        if (digits != 4 || f < 2009 || f > 2024)
            return 0;
    }
    else if (opt == MONTH) {
        if (digits != 2 || f < 1 || f > 12)
            return 0;
    }
    else if (opt == DAY) {
        if (digits != 2 || f < 1 || f > 31)
            return 0;
    }
    return 1;
}

int check_number(std::string str, int opt)
{
    std::string s;
    int i = 0;
    if (opt == 1)
        s = str.substr(i, 4);
    if (opt == 2 || opt == 3)
        s = str.substr(i, 2);
    if (!s[0])
        return 0;
    int dig = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        i++;
        dig++;
    }
    if (!check_date(s, opt, dig))
        return 0;
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
    float f = ft_stoi(s);
    return f;
}

std::string ft_trim(std::string str, int opt)
{
    std::string final;
    size_t start = str.find_first_not_of(" \t\v\f\r");
    size_t end = str.find_last_not_of(" \t\v\f\r");

    if (!str[start])
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

void    check_dates(std::string s1)
{
    size_t pos = s1.find('-');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input => " + s1));

    pos = s1.substr(pos + 1).find('-');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input => " + s1));

    std::string aux = split(s1, '-').second;

    std::string d1 = split(s1, '-').first;
    std::string d2 = split(aux, '-').first;
    std::string d3 = split(aux, '-').second;

    if (!check_number(d1, YEAR) || !check_number(d2, MONTH) || !check_number(d3, DAY))
        throw(std::invalid_argument("Error: invalid input => " + s1));
}

std::pair<std::string, float> check_line(std::string str)
{
    if (!str[0])
        throw(std::invalid_argument("Error: empty line"));

    size_t pos = str.find('|');
    if (pos == std::string::npos)
        throw(std::invalid_argument("Error: invalid input"));

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
            (void)it;
            (void)date;

    return 5;
}

void    BitcoinExchange::showValues(void)
{
    std::string str = "data.csv";
    this->populate(str);

    std::ifstream   f;
    f.open(this->input.c_str(), std::ios::in);
    std::string aux;
    getline(f, aux);
    if (!aux[0]) {
        std::cout << "Error: empty file" << std::endl;
        return ;
    }
    if (aux != "date | value") {
        std::cout << "Error: invalid file format" << std::endl;
        return ;
    }
    int i = 1;
    while (getline(f, aux)) {
        try {
            std::pair<std::string, float> pr = check_line(aux);
            std::cout << i << ". " << pr.first << " | " << pr.second << std::endl;

            // encontrar linha mais perto da db 1 (precisamos da data da linha)
            float closest_value = this->find_date(pr.first);
            // fazer conta (precisamos do rate da linha)
            (void)closest_value;
        }
        catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        i++;
    }
}
