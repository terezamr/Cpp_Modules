#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

class PmergeMe
{
    private:
        std::vector<int>    vec;
    public:
        PmergeMe(std::string str);

        void    FordJohnson();
        void    sortPair();
        void    sortPairs(size_t i0, size_t i1);
        std::vector<int>    get_a();
        std::vector<int>    get_b();
};

#endif