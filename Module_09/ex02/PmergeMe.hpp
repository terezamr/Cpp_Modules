#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <string>

class PmergeMe
{
    private:
        std::vector<int>    vec;
        std::list<int>      lst;
        std::deque<int>     dq;
        size_t              N;
        size_t              k;
    public:
        // Canonical Form
        PmergeMe(char **argv);

        void                FordJohnson_vec();
        void                FordJohnson_dq();

        // sorting functions
        void                sortPair();
        void                sortPairs(size_t i0, size_t i1);

        void                sortPair_dq();
        void                sortPairs_dq(size_t i0, size_t i1);
    
        // getters
        std::vector<int>    getV();
        std::deque<int>     getD();
        size_t              getN();

        // aux functions
        static size_t       get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index);
        std::string         ft_trim(std::string str);

        // template functions
        template <typename T>
        static size_t insertion_index(T ct, int target)
        {
            int high = ct.size() - 1;
            int low = 0;
            while (low <= high)
            {
                size_t mid = std::floor((high + low) / 2);
                if (ct[mid] == target)
                    return mid;
                else if (ct[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }

        // inserts the pend vector in the main chain
        template <typename T>
        T    insert_b(T &a, T &b)
        {
            size_t aux = 1;
            size_t f = 0;
            size_t smaller_index = 1;
            size_t jacob_order = 1;

            int index_b;
            while (f < b.size())
            {
                // uses the jacobshtal number to get the index of the
                // next element of b to insert in a
                aux = get_jacobsthal(aux, &jacob_order, &smaller_index);
                while (aux > b.size())
                    aux--;
                index_b = aux - 1;

                // binary search and insertion of b in a
                size_t index = insertion_index(a, b[index_b]);
                a.insert(a.begin() + index, b[index_b]);

                f++;
            }
            return (a);
        }

        // a main chain vector: high values of each pair
        // b pend elements vector: low values of each pair
        template <typename T>
        std::pair<T,T > get_a_b(T &v)
        {
            T a;
            T b;
            typename T::iterator it = v.begin();
            while (it + 1 != v.end() && it != v.end())
            {
                b.push_back(*it);
                a.push_back(*(it + 1));
                std::advance(it, 2);
            }
            if (it != v.end())
                b.push_back(*it);
            return std::make_pair(a, b);
        }

        template <typename T>
        static void print(T ct)
        {
            size_t h = 0;
            size_t i = 0;
            while (h < ct.size() && i < 5)
            {
                std::cout << ct[h] << " ";
                h++;
                i++;
            }
            if (h != ct.size())
                std::cout << " [...]";
            std::cout << "\n";
        }
};

#endif