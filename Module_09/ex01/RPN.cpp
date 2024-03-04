#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "Constructor" << std::endl;
}

RPN::~RPN()
{
    // std::cout << "Destructor" << std::endl;
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
                return -1;
        }
        f++;
    }
    float final = (i + static_cast<float>(m)/d);
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
    float nb = ft_stof(str);
    if (nb < 0 || nb > 10)
        return 0;
    return 1;
}

int    RPN::calculate(std::string s)
{
    if (st.size() < 2)
        return 0;
    if (s[1])
        return 0;
    float a = this->st.top();
    st.pop();
    float b = this->st.top();
    st.pop();
    if (s[0] == '+')
        st.push(a + b);
    else if (s[0] == '-')
        st.push(b - a);
    else if (s[0] == '*')
        st.push(b * a);
    else if (s[0] == '/')
        st.push(b / a);
    return 1;
}

int RPN::check_str(std::string str)
{
    std::string opt = "0123456789*/+- ";

    std::string aux;
	std::stringstream stream(str);
	while(std::getline(stream, aux, ' '))
    {
        if (aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/')
        {
            if (!this->calculate(aux))
                return 0;
        }
        else if (isNum(aux))
        {
            float nb = ft_stof(aux);
            this->st.push(nb);
        }
        else
            return 0;
    }
    std::cout << "final: " << this->st.top() << std::endl;
    return 1;
}

void    RPN::run(std::string str)
{
    if (!this->check_str(str))
        std::cout << "Bad input: check" << std::endl;
}
