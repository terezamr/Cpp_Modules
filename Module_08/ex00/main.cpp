#include "EasyFind.hpp"

int main(void)
{
    // vector - allows random access with []
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    std::cout << "v: " << vec[2] << std::endl;
    try
    {
        std::cout << "vector: " << easyfind(vec, 2) << std::endl;
        std::cout << "vector: " << easyfind(vec, 3) << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // list - doesnt allow access to a random element with []
    std::list <int> lst;
    lst.push_back(1);
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(5);
    try
    {
        std::cout << "list: " << easyfind(lst, 5) << std::endl;
        std::cout << "list: " << easyfind(lst, 10) << std::endl;
        std::cout << "list: " << easyfind(lst, -10) << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
