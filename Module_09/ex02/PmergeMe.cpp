#include "PmergeMe.hpp"

int   ft_stoi(std::string str)
{
    int f = 0;
    int i = 0;
    int sig = 1;

    if (str[f] == '+' || str[f] == '-' )
    {
        if (str[f] == '-' )
            sig = -1;
        f++;
    }
    while (str[f])
    {
        if (str[f] >= '0' && str[f] <= '9')
            i = i * 10 + (str[f] - '0');
        f++;
    }
    return (i * sig);
}

void    PmergeMe::sortPair()
{
    size_t i = 0;
    while (i < vec.size())
    {
        if (this->vec[i + 1] && this->vec[i] > this->vec[i + 1])
            iter_swap(vec.begin() + i, vec.begin() + i + 1);
        i = i + 2;
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

// main chain vector: high values of each pair
std::vector<int>    PmergeMe::get_a()
{
    std::vector<int> a;
    size_t i = 1;
    while (i < vec.size())
    {
        a.push_back(this->vec[i]);
        i = i + 2;
    }
    return a;
}

// pend elements vector: low values of each pair
std::vector<int>    PmergeMe::get_b()
{
    std::vector<int> b;
    size_t i = 0;
    while (i < this->vec.size())
    {
        b.push_back(this->vec[i]);
        i = i + 2;
    }
    return b;
}

size_t jacobsthal_equation(int order)
{
    if (order == 1)
        return 1;
    else
        return ((std::pow(2, order) - std::pow(-1, order)) / 3);
}

size_t    get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index)
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

std::vector<int>    insert_b(std::vector<int> a, std::vector<int> b)
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
    return (a);
}

void    PmergeMe::FordJohnson_vec()
{
    // sort each pair
    this->sortPair();

    // sort pairs recursively (highest value)
    size_t i = 0;
    while (i < vec.size())
    {
        size_t g = 1;
        while (g < vec.size() - 2)
        {
            this->sortPairs(g, g + 2);
            g = g + 2;
        }
        i++;
    }

    std::vector<int> a = this->get_a();
    std::vector<int> b = this->get_b();

    std::vector<int> vector = insert_b(a, b);
    this->vec = vector;
}

void    PmergeMe::print_v()
{
    size_t h = 0;
    while (h < this->vec.size())
    {
        std::cout << this->vec[h] << " ";
        h++;
    }
    std::cout << "\n";
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
    gettimeofday(&start, NULL);
    int i = 1;
    while (argv[i])
    {
        std::string aux = argv[i];
        int nb = ft_stoi(ft_trim(aux.c_str()));
        this->vec.push_back(nb);
        i++;
    }
    this->FordJohnson_vec();
}

PmergeMe::PmergeMe(char **argv, int opt)
{
    gettimeofday(&start, NULL);
    int i = 1;
    while (argv[i])
    {
        std::string aux = argv[i];
        int nb = ft_stoi(ft_trim(aux.c_str()));
        this->lst.push_back(nb);
        i++;
    }
    this->FordJohnson_lst();
}

double  PmergeMe::getTime()
{
    gettimeofday(&end, NULL);
    return (double(end.tv_usec - start.tv_usec));
}
