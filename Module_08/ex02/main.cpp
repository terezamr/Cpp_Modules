#include "MutantStack.hpp"

int main(void)
{
    {
        MutantStack<int> mstack;

        mstack.push(1);
        mstack.push(2);
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Top: " << mstack.top() << std::endl;
        std::cout << "Size: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(4);

        MutantStack<int>::iterator it;
        for (it = mstack.begin(); it != mstack.end(); it++)
            std::cout << "mstack: " << *it << std::endl;

        it = mstack.begin();
        ++it;
        ++it;
        --it;
        std::cout << "One step forward: " << *it << std::endl;

        // end() returns the iterator which points to the 
        // (imaginary) element next to the last
        MutantStack<int>::iterator ite = mstack.end();
        --ite;
        --ite;
        --ite;
        std::cout << "First: " << *ite << std::endl;

        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
    }
    {
        std::cout << "-------LIST-------" << std::endl;
        std::list<int>  lst;
        lst.push_back(1);
        lst.push_back(2);
        std::cout << "Top: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "Top: " << lst.back() << std::endl;
        std::cout << "Size: " << lst.size() << std::endl;

        lst.push_back(3);
        lst.push_back(4);

        std::list<int>::iterator it;
        for (it = lst.begin(); it != lst.end(); it++)
            std::cout << "lst: " << *it << std::endl;

        it = lst.begin();
        ++it;
        ++it;
        --it;
        std::cout << "One step forward: " << *it << std::endl;
        
        std::list<int>::iterator ite = lst.end();
        --ite;
        --ite;
        --ite;
        std::cout << "First: " << *ite << std::endl;

        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}
