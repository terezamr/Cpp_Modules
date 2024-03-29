#include "PmergeMe.hpp"

size_t  jacobsthal_equation(int order)
{
    if (order == 1)
        return 1;
    else
        return ((std::pow(2, order) - std::pow(-1, order)) / 3);
}

size_t  PmergeMe::get_jacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index)
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


// not recursive function to sort pairs, according to the highest value
// void    PmergeMe::sortPairs(size_t i0, size_t i1)
// {
//     if (i1 >= vec.size())
//         return ;
//     if (vec[i0] > vec[i1])
//     {
//         iter_swap(vec.begin() + i0, vec.begin() + i1);
//         iter_swap(vec.begin() + i0 - 1, vec.begin() + i1 - 1);
//     }
//     /*
//         // to insert in the main loop after sorting each pair of two
//         size_t i = 0;
//         while (i < vec.size() - 1)
//         {
//             size_t g = 1;
//             while (g < vec.size() - 2)
//             {
//                 this->sortPairs(g, g + 2);
//                 g = g + 2;
//             }
//             i++;
//         }
//     */
// }