#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class ScalarConverter {
    private:
        std::string name;
        char        c;
        int         i;
        float       f;
        double      d;
    public:
    // no need of an instance in order to use a static method 
        ScalarConverter(void);
        ScalarConverter(std::string str);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter(void);
        ScalarConverter& operator=(const ScalarConverter& src);
        
        char    getC() const;
        int     getI() const;
        float   getF() const;
        double  getD() const;

        void    convert(void);
};

std::ostream & operator<<(std::ostream & o, ScalarConverter b);

#endif