#include "EasyFind.hpp"

// check unordered maps

int main(void)
{
    // vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    try
    {
        std::cout << "vector: ";
        easyfind(vec, 2);
        easyfind(vec, 3);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // list (iteration both in front and back)
    std::list <int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i);
    try
    {
        std::cout << "list: ";
        easyfind(lst, 5);
        easyfind(lst, 11);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
