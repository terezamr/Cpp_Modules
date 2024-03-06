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

void    PmergeMe::sortPairs()
{
    int i = 0;
    while (this->vec[i])
    {
        if (this->vec[i + 1] && this->vec[i] > this->vec[i + 1])
            iter_swap(vec.begin() + i, vec.begin() + i + 1);
        
        i = i + 2;
    }
    
    i = 0;
    std::cout << "sorted pairs: ";
    while(this->vec[i])
    {
        std::cout << vec[i] << " ";
        i++;
    }
    std::cout << "\n";
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

    size_t f = 0;
    std::cout << "a: ";
    while (f < a.size())
    {
        std::cout << a[f] << " ";
        f++;
    }
    std::cout << "\n";
    return a;
}

// pend elements vecotr: low values of each pair
std::vector<int>    PmergeMe::get_b()
{
    std::vector<int> b;
    size_t i = 0;
    while (i < this->vec.size())
    {
        b.push_back(this->vec[i]);
        i = i + 2;
    }

    size_t f = 0;
    std::cout << "b: ";
    while (f < b.size())
    {
        std::cout << b[f] << " ";
        f++;
    }
    std::cout << "\n";
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

    while (f < b.size())
    {
        aux = get_jacobsthal(aux, &jacob_order, &smaller_index);
        while (aux > b.size())
            aux--;
        std::cout << "b: "<< b[aux - 1] << "\n";
        f++;
    }
    return (a);
}


void    PmergeMe::FordJohnson()
{
    this->sortPairs();

    std::vector<int> a = this->get_a();
    std::vector<int> b = this->get_b();

    std::vector<int> vector = insert_b(a, b);
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

    int i = 0;
    while(this->vec[i])
    {
        std::cout << vec[i] << " ";
        i++;
    }
    std::cout << "\n";
    this->FordJohnson();
}
