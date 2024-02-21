#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <limits>

// Check data type
bool    isInt(std::string str);
bool    isChar(std::string str);
bool    isFloat(std::string str);
bool    isDouble(std::string str);
bool    isSpecial(std::string str);

// Case functions
void    caseInt(std::string str);
void    caseChar(std::string str);
void    caseFloat(std::string str);
void    caseDouble(std::string str);

// Printing functions
void    printChar(char c, int i);
void    printI(std::string str, int i, float f, double d);
void    printFloat(std::string str, float f, double d);
void    printDouble(double d);
void    printValue(std::string str, int i, float f, double d, char c);
void    printSpecial(std::string str);


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter& operator=(const ScalarConverter& src);
    public:
        ~ScalarConverter();
        static void convert(std::string str);
};

#endif