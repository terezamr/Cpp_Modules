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
    std::list<int> lst;
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

    // deque - double ended queue (memory not contiguous)
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(5);
    dq.push_front(10);
    std::deque<int>::iterator it = dq.begin();
    it++;
    dq.insert(it, 2);
    try
    {
        std::cout << "deque: " << dq[0] << std::endl;
        std::cout << "deque: " << dq[1] << std::endl;
        std::cout << "deque: " << dq[2] << std::endl;
        std::cout << "deque: " << dq[3] << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
