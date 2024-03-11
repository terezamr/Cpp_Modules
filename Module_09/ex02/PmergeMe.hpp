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
        std::list<int>      lst;
        struct timeval start, end;
    public:
        PmergeMe(char **argv);
        PmergeMe(char **argv, int opt);

        void                FordJohnson_vec();
        void                FordJohnson_lst();

        void                sortPair();
        void                sortPair_lst();

        void                sortPairs(size_t i0, size_t i1);
        void                sortPairs_lst(size_t i0, size_t i1);

        std::vector<int>    get_a();
        std::vector<int>    get_b();

        std::list<int>      get_a_lst();
        std::list<int>      get_b_lst();

        void                print_v();
        void                print_l();
        double              getTime();
};

size_t       get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index);

#endif