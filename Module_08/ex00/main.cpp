#include "EasyFind.hpp"

int main(void)
{
    // vector - allows random access with []
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
    for (int i = 0; i < 5; i++)
        std::cout << "v: " << vec[i] << std::endl;

    std::cout << "-----------" << std::endl;

    try
    {
        std::cout << "vector: " << easyfind(vec, 2) << std::endl;
        std::cout << "vector: " << easyfind(vec, 3) << std::endl;
        std::cout << "vector: " << easyfind(vec, 13) << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "-----------" << std::endl;

    // list - doesnt allow random access with []
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(5);
    lst.push_back(10);
    lst.push_front(5);

    std::list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); *it++)
        std::cout << "lst: " << *it << std::endl;

    std::cout << "-----------" << std::endl;

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
