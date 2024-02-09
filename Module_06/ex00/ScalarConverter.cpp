#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    //std::cout << "ScalarConverter created." << std::endl;
    this->name = "";
    this->c = 0;
    this->i = 0;
    this->f = 0.0f;
    this->d = 0.0;
}

ScalarConverter::ScalarConverter(std::string str)
{
    //std::cout << "ScalarConverter created." << std::endl;
    this->name = str;
    this->c = 0;
    this->i = 0;
    this->f = 0.0f;
    this->d = 0.0;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    //std::cout << "Copy assigment." << std::endl;
    this->name = src.name;
    this->c = src.getC();
    this->i = src.getI();
    this->f = src.getF();
    this->d = src.getD();
}

ScalarConverter::~ScalarConverter()
{
    //std::cout << "ScalarConverter destroyed." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    if (this != &src)
    {
        this->c = src.getC();
        this->i = src.getI();
        this->f = src.getF();
        this->d = src.getD();
    }
    return *this;
}

char    ScalarConverter::getC() const
{
    return(this->c);
}

int    ScalarConverter::getI() const
{
    return(this->i);
}

float    ScalarConverter::getF() const
{
    return(this->f);
}

double    ScalarConverter::getD() const
{
    return(this->d);
}

std::ostream & operator<<(std::ostream & o, ScalarConverter b)
{
   std::cout << "Char: " << b.getC() << std::endl;
   std::cout << "Int: " << b.getI() << std::endl;
   std::cout << "Float: " << b.getF() << std::endl;
   std::cout << "Double: " << b.getD() << std::endl;
   return o;
}

int check_isInt(std::string name)
{
    int i = 0;
    while (name[i])
    {
        std::cout << name[i] << std::endl;
        if (name[i] >= '0' && name[i] <= 9)
            return (0);
        i++;
    }
    return (1);
}

void    ScalarConverter::convert(void)
{
    if (!check_isInt(name))
        std::cout << "is an int" << std::endl;
}
