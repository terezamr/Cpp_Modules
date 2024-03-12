#include "PmergeMe.hpp"

std::vector<int>     PmergeMe::getV()
{
    return (this->vec);
}

std::deque<int>     PmergeMe::getD()
{
    return (this->dq);
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
    if (i1 >= vec.size())
        return ;
    if (vec[i0] < vec[i1])
        sortPairs(i1, i1 + 2);
    else if (vec[i0] > vec[i1])
    {
        iter_swap(vec.begin() + i0, vec.begin() + i1);
        iter_swap(vec.begin() + i0 - 1, vec.begin() + i1 - 1);
    }
}

size_t  jacobsthal_equation(int order)
{
    if (order == 1)
        return 1;
    else
        return ((std::pow(2, order) - std::pow(-1, order)) / 3);
}

size_t  get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index)
{
    if (i - 1 != 0 && i - 1 != jacobsthal_equation(*jacob_order - 1)) // decrementing elements after the jc number
        i--;
    else // next jc number and first element cases
    {
        (*jacob_order)++;
        *smaller_index = i;
        i = jacobsthal_equation(*jacob_order);
    }
    return i;
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
    std::vector<int> vector = insert_b(ab.first, ab.second);
    this->vec = vector;
}

std::string ft_trim(std::string str)
{
    std::string final;
    size_t start = str.find_first_not_of(" \t\v\f\r");
    size_t end = str.find_last_not_of(" \t\v\f\r");

    if (start == std::string::npos)
       throw(std::invalid_argument("Error: empty str"));

    final = str.substr(start, end - start + 1);
    return final;
}

PmergeMe::PmergeMe(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        std::istringstream iss(argv[i]);
        int n;
        if (!(iss >> n))
            throw(std::invalid_argument("Invalid argument"));
        this->vec.push_back(n);
        i++;
    }
}
