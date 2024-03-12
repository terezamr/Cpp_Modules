#include "PmergeMe.hpp"

void    PmergeMe::sortPairs_dq(size_t i0, size_t i1)
{
    if (i1 >= this->dq.size())
        return ;
    if (dq[i0] < dq[i1])
        sortPairs_dq(i1, i1 + 2);
    else if (dq[i0] > dq[i1])
    {
        std::swap(dq[i0], dq[i1]);
        std::swap(dq[i0 - 1], dq[i1 - 1]);
    }
}

void    PmergeMe::sortPair_dq()
{
    size_t i = 0;
    while (i < this->dq.size())
    {
        if (this->dq[i + 1] && dq[i] > dq[i + 1])
            std::swap(dq[i], dq[i + 1]);
        i = i + 2;
    }
}

// main chain deque: high values of each pair
std::deque<int>    PmergeMe::get_a_dq()
{
    std::deque<int> a;
    size_t i = 1;
    while (i < dq.size())
    {
        a.push_back(dq[i]);
        i = i + 2;
    }
    return a;
}

// pend elements deque: low values of each pair
std::deque<int>    PmergeMe::get_b_dq()
{
    std::deque<int> b;
    size_t i = 0;
    while (i < dq.size())
    {
        b.push_back(dq[i]);
        i = i + 2;
    }
    return b;
}

std::deque<int>    insert_b_dq(std::deque<int> a, std::deque<int> b)
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

        // inserts the element of b in a
        size_t i = 0;
        while (i < a.size())
        {
            if (b[index_b] < a[i])
            {
                a.insert(a.begin() + i, b[index_b]);
                break ;
            }
            i++;
        }
        f++;
    }
    return a;
}

void    PmergeMe::FordJohnson_dq()
{
    // sort each pair
    this->sortPair_dq();

    // sort pairs recursively (highest value)
    size_t i = 0;
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
    
    std::deque<int> a = this->get_a_dq();
    std::deque<int> b = this->get_b_dq();
    std::deque<int> final_dq = insert_b_dq(a, b);

    this->dq = final_dq;
}

void    PmergeMe::print_dq()
{
    int i = 0;
    size_t g = 0;
    while (g < this->dq.size() && i < 5)
    {
        std::cout << dq[g] << " ";
        g++;
        i++;
    }
    if (g != this->dq.size())
        std::cout << " [...]\n";
}
