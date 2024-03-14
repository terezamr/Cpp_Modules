#include "PmergeMe.hpp"
#include <utility>

std::vector<int>    PmergeMe::getV()
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

// recursive function to sort pairs
void	sortPairs_recursive(std::vector<int> &vec, size_t size)
{
	if (size >= vec.size())
		return ;
	for (size_t i = 1; i < vec.size() - 1; i+=2) {
        if (vec[i] > vec[size]) {
			std::swap(vec[i], vec[size]);
			std::swap(vec[i - 1], vec[size - 1]);
		}
	}
	sortPairs_recursive(vec, size + 2);
}

void    PmergeMe::FordJohnson_vec()
{
    // sort each pair
    this->sortPair();

    int odd = 0;
    int last = vec[vec.size() - 1];
    if (vec.size() % 2 != 0)
    {
        odd = 1;
        vec.erase(vec.end() - 1);
    }

    // sort pairs recursively (according to highest value)
    sortPairs_recursive(this->vec, 1);

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
