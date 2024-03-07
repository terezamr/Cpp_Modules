#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>
# include  <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int>    vec;
        struct timeval start, end;
    public:
        PmergeMe(char **argv);
        PmergeMe(char **argv, int opt);

        void                FordJohnson_vec();
        void                sortPair();
        void                sortPairs(size_t i0, size_t i1);
        std::vector<int>    get_a();
        std::vector<int>    get_b();
        void                print_v();
        double              getTime();
};

#endif