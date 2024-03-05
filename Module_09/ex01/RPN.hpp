#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <stack>

class RPN
{
    private:
        std::stack<float> st;
    public:
        RPN();
        ~RPN();
        RPN(const RPN&src);
        RPN&    operator=(const RPN& src);

        int     populate_st(std::string str);
        int     check_str(std::string str);
        int    calculate(std::string s);
        void    run(std::string str);
};

#endif
