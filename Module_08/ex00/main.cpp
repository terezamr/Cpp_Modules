#include "EasyFind.hpp"

// check unordered maps

int main(void)
{
    // array
    std::array<int, 5> arr = {1, 35, 3, 4, 5};
    std::cout << "array: ";
    try
    {
        easyfind(arr, 5);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    std::cout << "vector: ";
    try
    {
        easyfind(vec, 2);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // list (iteration both in front and back)
    std::list <int> lst;
    for (int i = 1; i <= 5; i++)
        lst.push_back(i);
    std::cout << "list: ";
    try
    {
        easyfind(lst, 11);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // forward list (one way only)
    std::forward_list<int> fr_lst = {1, 2, 3, 4, 5};
    std::cout << "forward list: ";
    try
    {
        easyfind(fr_lst, 4);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // unordered set (doesnt allow duplicates)
    std::unordered_set <int> s1;
    s1.insert(12);
    s1.insert(12);
    std::cout << "unordered set: ";
    try
    {
        easyfind(s1, 12);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    

    // unordered multiset ( allow duplicates)
    std::unordered_multiset <int> s2;
    s2.insert(13);
    s2.insert(13);
    std::cout << "unordered multiset: ";
    try
    {
        easyfind(s2, 12);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    // unordered map (combination of key value and mapped value)
    // std::unordered_map<int, int> m1 = {{1, 4}, {2, 5}};
    // std::cout << "unordered map: ";
    // try
    // {
    //     easyfind(m1, 12);
    // }
    // catch (std::exception &error)
    // {
    //     std::cout << error.what() << std::endl;
    // }
    return 0;
}
