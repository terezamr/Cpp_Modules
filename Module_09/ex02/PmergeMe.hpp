#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int>    vec;
        std::list<int>      lst;
        std::deque<int>      dq;
        struct timeval start, end;
    public:
        PmergeMe(char **argv);
        PmergeMe(char **argv, int opt);
        PmergeMe(char **argv, char *str);

        void                FordJohnson_vec();
        void                FordJohnson_lst();
        void                FordJohnson_dq();

        void                sortPair();
        void                sortPair_lst();
        void                sortPair_dq();

        void                sortPairs(size_t i0, size_t i1);
        void                sortPairs_lst(size_t i0, size_t i1);
        void                sortPairs_dq(size_t i0, size_t i1);

        std::vector<int>    get_a();
        std::vector<int>    get_b();
        std::pair<std::vector<int>,std::vector<int> > get_a_b();

        std::list<int>      get_a_lst();
        std::list<int>      get_b_lst();

        std::deque<int>    get_a_dq();
        std::deque<int>    get_b_dq();

        void                print_v();
        void                print_l();
        void                print_dq();
    
        double              getTime();
};

size_t       get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index);

#endif