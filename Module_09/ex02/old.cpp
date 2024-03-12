// main chain vector: high values of each pair
std::vector<int>    PmergeMe::get_a()
{
    std::vector<int> a;
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
         //std::cout << "i: " << i << std::endl;
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

        // binary search and insertion of b in a
        size_t index = insertion_index(a, b[index_b]);
        a.insert(a.begin() + index, b[index_b]);

        f++;
    }
    return (a);
}

PmergeMe::PmergeMe(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        std::string aux = argv[i];
        int nb = ft_stoi(ft_trim(aux.c_str()));
        this->vec.push_back(nb);
        this->dq.push_back(nb);
        i++;
    }
}

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
