#include "PmergeMe.hpp"

std::deque<int>     PmergeMe::getD()
{
    return (this->dq);
}

void    PmergeMe::sortPair_dq()
{
    for (size_t i = 0; i + 1 < dq.size(); i += 2)
    {
        if (this->dq[i + 1] && dq[i] > dq[i + 1])
            std::swap(dq[i], dq[i + 1]);
    }
}

void    PmergeMe::sortPairs_dq(size_t i0, size_t i1)
{
    if (i1 >= this->dq.size())
        return ;
    if (dq[i0] > dq[i1])
    {
        std::swap(dq[i0], dq[i1]);
        std::swap(dq[i0 - 1], dq[i1 - 1]);
    }
    //if (dq[i0] < dq[i1])
    //    sortPairs_dq(i1, i1 + 2);

}

void    PmergeMe::FordJohnson_dq()
{
    // sort each pair
    this->sortPair_dq();

    // sort pairs recursively (highest value)
    size_t i = 0;
    int odd = 0;
    int last = dq[dq.size() - 1];
    if (dq.size() % 2 != 0)
    {
        odd = 1;
        dq.erase(dq.end() - 1);
    }

    while (i < dq.size())
    {
        size_t g = 1;
        while (g < dq.size() - 2)
        {
            this->sortPairs_dq(g, g + 2);
            g = g + 2;
        }
        i++;
    }

    if (odd == 1)
        dq.insert(dq.end(), last);
    
    std::pair<std::deque<int>,std::deque<int> > ab = get_a_b(dq);
    std::deque<int> final_dq = PmergeMe::insert_b(ab.first, ab.second);
    this->dq = final_dq;
}
