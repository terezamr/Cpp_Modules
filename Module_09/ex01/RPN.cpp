#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) : st(src.st) {}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
        this->st = src.st;
    return *this;
}

int RPN::populate_st(std::string str)
{
    int i = 0;
    std::string ws = " \t";
    std::string op = "+-/*";
    while (str[i])
    {
        if ((std::isdigit(str[i]) && ws.find(str[i + 1]) != std::string::npos) || ws.find(str[i]) != std::string::npos)
            this->st.push(str[i]);
        else
            return 0;
        i++;
    }
    return 1;
}

float   ft_stof(std::string str)
{
    int f = 0;
    int m = 0;
    float i = 0;
    int d = 1;
    int sig = 1;

    if (str[f] == '-' || str[f] == '+')
    {
        if (str[f] == '-')
            sig = -1;
        f++;
    }
    while (str[f])
    {
        if (str[f] >= '0' && str[f] <= '9')
            i = i * 10 + (str[f] - '0');
        else if (str[f] == '.')
        {
            f++;
            if (!str[f] || !isdigit(str[f]))
                return -1;
            while (str[f] >= '0' && str[f] <= '9')
            {
                m = m * 10 + (str[f] - '0');
                d *= 10;
                f++;
            }
            if (str[f] == '.')
                throw(std::invalid_argument("Error: bad input"));
            continue ;
        }
        f++;
    }
    float final = (i + static_cast<float>(m)/d) * sig;
    return (final);
}

std::pair<std::string,std::string> split(std::string str)
{
    std::size_t found = str.find_first_of(" \t");
    std::string s1 = str.substr(0, found);
    std::string s2 = str.substr(found + 1);
    
    return std::make_pair(s1, s2);
}

int isNum(std::string str)
{
    if ((str[0] == '+' || str[0] == '-') && isdigit(str[1]))
        return 1;
    if (isdigit(str[0]))
        return 1;

    return 0;
}

int    RPN::calculate(std::string s)
{
    if (st.size() < 2)
        return 0;
    float a = this->st.top();
    st.pop();
    float b = this->st.top();
    st.pop();
    if (s[0] == '+')
        st.push(b + a);
    else if (s[0] == '-')
        st.push(b - a);
    else if (s[0] == '*')
        st.push(b * a);
    else if (s[0] == '/')
    {
        if (a == 0)
            throw(std::invalid_argument("Error: Division by zero"));
        st.push(b / a);
    }
    // std::cout << "calc: " << st.top() << std::endl;
    return 1;
}

void    RPN::run(std::string str)
{
    if (!str[0] || str[0] == ' ')
        throw(std::invalid_argument("Error: bad input"));

    std::string aux;
	std::stringstream stream(str);
	while(std::getline(stream, aux, ' '))
    {
        std::cout << "aux:" << aux << "." << std::endl;
        if (isNum(aux))
        {
            float nb = ft_stof(aux);
            if (nb < -9 || nb > 9)
                throw(std::invalid_argument("Error: bad input"));
            this->st.push(nb);
        }
        else if ((aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/') && !aux[1])
        {
            if (!this->calculate(aux))
                throw(std::invalid_argument("Error: bad input"));
        }
        else
            throw(std::invalid_argument("Error: bad input"));
    }
    if (this->st.size() != 1)
        throw(std::invalid_argument("Error: bad input"));
    std::cout << this->st.top() << std::endl;
}
