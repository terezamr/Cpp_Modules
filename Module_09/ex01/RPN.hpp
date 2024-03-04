#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
//#include <cmath>
//#include <algorithm>
#include <stack>

class RPN
{
    private:
        std::stack<float> st;
    public:
        RPN();
        ~RPN();

        int     populate_st(std::string str);
        int     check_str(std::string str);
        int    calculate(std::string s);
        void    run(std::string str);
};

#endif
