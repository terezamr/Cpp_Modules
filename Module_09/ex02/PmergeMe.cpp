#include "PmergeMe.hpp"

std::vector<int>     PmergeMe::getV()
{
    return (this->vec);
}

size_t  PmergeMe::getN()
{
    return (this->N);
}

void    PmergeMe::sortPair()
{
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (this->vec[i + 1] && this->vec[i] > this->vec[i + 1])
            iter_swap(vec.begin() + i, vec.begin() + i + 1);
    }
}

void    PmergeMe::sortPairs(size_t i0, size_t i1)
{
    std::cout << "sp\n";
    // if (i1 >= vec.size())
    //     return ;
    // if (vec[i0] < vec[i1])
    //     sortPairs(i1, i1 + 2);
    // else if (vec[i0] > vec[i1])
    // {
    //     iter_swap(vec.begin() + i0, vec.begin() + i1);
    //     iter_swap(vec.begin() + i0 - 1, vec.begin() + i1 - 1);
    // }

    if (i1 >= vec.size())
        return ;
    if (vec[i0] > vec[i1])
    {
        iter_swap(vec.begin() + i0, vec.begin() + i1);
        iter_swap(vec.begin() + i0 - 1, vec.begin() + i1 - 1);
    }

    std::vector<size_t> permutation;
    for (size_t i = i0 + 2; i < vec.size(); i += 2) {
        if (vec[i] > vec[i + 1])
            permutation.push_back(i);
    }

    // Apply permutation to smaller elements
    for (size_t i : permutation) {
        std::iter_swap(vec.begin() + i, vec.begin() + i + 1);
    }

    // Recursively sort larger elements
    for (size_t i : permutation) {
        sortPairs(i, i + 2);
    }
}

void    PmergeMe::FordJohnson_vec()
{
    // sort each pair
    this->sortPair();

    // sort pairs recursively (highest value)
    size_t i = 0;
    int odd = 0;
    int last = vec[vec.size() - 1];
    if (vec.size() % 2 != 0)
    {
        odd = 1;
        vec.erase(vec.end() - 1);
    }

    while (i < vec.size() - 1)
    {
        size_t g = 1;
        while (g < vec.size() - 2)
        {
            this->sortPairs(g, g + 2);
            g = g + 2;
        }
        i++;
    }

    if (odd == 1)
        vec.insert(vec.end(), last);

    std::pair<std::vector<int>,std::vector<int> > ab = get_a_b(vec);
    std::vector<int> vector = PmergeMe::insert_b(ab.first, ab.second);

    this->vec = vector;
}


bool isSorted(std::vector<int> &v)
{
    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator aux = v.begin() + 1;
    while (aux != v.end())
    {
        if (*it > *aux)
            return (false);
        it++;
        aux++;
    }
    return (true);
}

PmergeMe::PmergeMe(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        std::istringstream iss(argv[i]);
        int n;

        std::string str = argv[i];
        size_t nonDigit = str.find_first_not_of("0123456789");

        if (nonDigit != std::string::npos || !(iss >> n)) {
            throw(std::invalid_argument("Invalid argument"));
        }
        this->vec.push_back(n);
        this->dq.push_back(n);
        i++;
    }
    this->N = vec.size();
    if (isSorted(vec))
        throw(std::invalid_argument("Set of numbers is sorted"));

}
