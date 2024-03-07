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
    while (str[f] >= '0' && str[f] <= '9')
    {
        i = i * 10 + (str[f] - '0');
        f++;
    }
    return (i * sig);
}

void    PmergeMe::sortPair()
{
    int i = 0;
    while (this->vec[i])
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
    int i = 1;
    while (this->vec[i])
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

void    PmergeMe::FordJohnson()
{
    size_t h = 0;
    std::cout << "vec 0: ";
    while (h < vec.size())
    {
        std::cout << vec[h] << " ";
        h++;
    }
    std::cout << "\n";

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

    h = 0;
    std::cout << "vec f: ";
    while (h < vector.size())
    {
        std::cout << vector[h] << " ";
        h++;
    }
    std::cout << "\n";
}

PmergeMe::PmergeMe(std::string str)
{

    std::string aux;
	std::stringstream stream(str);
	while(stream >> aux)
    {
        int nb = ft_stoi(aux);
        this->vec.push_back(nb);
    }

    this->FordJohnson();
}
