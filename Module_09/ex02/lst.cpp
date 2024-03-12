#include "PmergeMe.hpp"

std::list<int>::iterator    next_lst(std::list<int> &lst, size_t i)
{
    size_t f = 0;
    std::list<int>::iterator it = lst.begin();
    //std::advance(it, i);
    while (it != lst.end() && f < i)
    {
        it++;
        f++;
    }
    return it;
}

void    PmergeMe::sortPairs_lst(size_t i0, size_t i1)
{
    if (i1 >= this->lst.size())
        return ;
    std::list<int>::iterator aux0 = next_lst(this->lst, i0);
    std::list<int>::iterator aux1 = next_lst(this->lst, i1);
    if (*aux0 < *aux1)
        sortPairs_lst(i1, i1 + 2);
    else if (*aux0 > *aux1)
    {
        std::iter_swap(aux0, aux1);
        std::iter_swap(next_lst(this->lst, i0 - 1), next_lst(this->lst, i1 - 1));
    }
}

void    PmergeMe::sortPair_lst()
{
    size_t i = 0;
    while (i < this->lst.size())
    {
        std::list<int>::iterator aux0 = next_lst(this->lst, i);
        std::list<int>::iterator aux1 = next_lst(this->lst, i + 1);
        if (*aux0 > *aux1)
            std::iter_swap(aux0, aux1);
        i = i + 2;
    }
}

// main chain list: high values of each pair
std::list<int>    PmergeMe::get_a_lst()
{
    std::list<int> a;
    std::list<int>::iterator it = lst.begin();
    it++;
    size_t i = 0;
    while (it != lst.end() && i < lst.size())
    {
        a.push_back(*it);
        it++;
        it++;
        i = i + 2;
    }
    return a;
}

// pend elements list: low values of each pair
std::list<int>    PmergeMe::get_b_lst()
{
    std::list<int> b;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        b.push_back(*it);
        it++;
        it++;
    }
    return b;
}

std::list<int>    insert_b(std::list<int> a, std::list<int> b)
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
            std::list<int>::iterator aux0 = next_lst(b, index_b);
            std::list<int>::iterator aux1 = next_lst(a, i);
            if (*aux0 < *aux1)
            {
                a.insert(aux1, *aux0);
                break ;
            }
            i++;
        }
        f++;
    }
    return a;
}

void    PmergeMe::FordJohnson_lst()
{
    // sort each pair
    this->sortPair_lst();

    // sort pairs recursively (highest value)
    size_t i = 0;
    while (i < lst.size())
    {
        size_t g = 1;
        while (g < lst.size() - 2)
        {
            this->sortPairs_lst(g, g + 2);
            g = g + 2;
        }
        i++;
    }

    std::list<int> a = this->get_a_lst();
    std::list<int> b = this->get_b_lst();
    std::list<int> final_list = insert_b(a, b);

    this->lst = final_list;
}

void    PmergeMe::print_l()
{
    int i = 0;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end() && i < 5)
    {
        std::cout << *it << " ";
        it++;
        i++;
    }
    if (it != lst.end())
        std::cout << " [...]\n";
}
