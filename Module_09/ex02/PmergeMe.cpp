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

// main chain vector: high values of each pair
std::vector<int>    PmergeMe::get_a()
{
    std::vector<int> a;
    // std::copy_if(vec.begin(), vec.end(), std::back_inserter(evenNumbers),
    //     [](int num){ return num % 2 == 0; });

    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        a.push_back(*it);
        std::advance(it, 2);
    }
    return a;
}

// pend elements vector: low values of each pair
std::vector<int>    PmergeMe::get_b()
{
    std::vector<int> b;
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        b.push_back(*it);
        std::advance(it, 2);
    }
    return b;
}

std::pair<std::vector<int>,std::vector<int> > PmergeMe::get_a_b()
{
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int>::iterator it = vec.begin();
    while (it + 1 != vec.end() && it != vec.end())
    {
        // std::cout << *it << " ";
        b.push_back(*it);
        a.push_back(*(it + 1));
        std::advance(it, 2);
    }
    return std::make_pair(a, b);
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

size_t insertion_index(std::vector<int> v, int target)
{
    int high = v.size() - 1;
    int low = 0;
    while (low <= high)
    {
        size_t mid = std::floor((high + low) / 2);
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
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

        // binary search and insertion
        size_t index = insertion_index(a, b[index_b]);
        a.insert(a.begin() + index, b[index_b]);

        // inserts the element of b in a
        // size_t i = 0;
        // while (i < a.size())
        // {
        //     //std::cout << "i: " << i << std::endl;
        //     if (b[index_b] < a[i])
        //     {
        //         a.insert(a.begin() + i, b[index_b]);
        //         break ;
        //     }
        //     i++;
        // }
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

    std::pair<std::vector<int>,std::vector<int> > ab = get_a_b();
    
    // std::vector<int> a = this->get_a();
    // std::vector<int> b = this->get_b();

    std::vector<int> vector = insert_b(ab.first, ab.second);
    this->vec = vector;
}

void    PmergeMe::print_v()
{
    int i = 0;
    size_t h = 0;
    while (h < this->vec.size() && i < 5)
    {
        std::cout << this->vec[h] << " ";
        h++;
        i++;
    }
    if (h != vec.size())
        std::cout << " [...]\n";
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
    (void)opt;
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

PmergeMe::PmergeMe(char **argv, char *str)
{
    (void)str;
    gettimeofday(&start, NULL);
    int i = 1;
    while (argv[i])
    {
        std::string aux = argv[i];
        int nb = ft_stoi(ft_trim(aux.c_str()));
        this->dq.push_back(nb);
        i++;
    }
    this->FordJohnson_dq();
}

double  PmergeMe::getTime()
{
    gettimeofday(&end, NULL);
    return (double(end.tv_usec - start.tv_usec));
}
