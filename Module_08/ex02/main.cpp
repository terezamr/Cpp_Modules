#include "MutantStack.hpp"

int main(void)
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

    std::cout << "Size: " << mstack.size() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    ++it;
    ++it;
    --it;
    std::cout << "Two steps forward: " << *it << std::endl;

    MutantStack<int>::iterator ite = mstack.end();
    --ite;
    --ite;
    --ite;
    std::cout << "First: " << *ite << std::endl;

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "--------------" << std::endl;
    
    MutantStack<int>::iterator i = mstack.begin();
    MutantStack<int>::iterator ie = mstack.end();
    while (i != ie)
    {
    std::cout << *i << std::endl;
    ++i;
    }

    std::cout << "--------------" << std::endl;

    MutantStack<int> mstack2(mstack);
    for (MutantStack<int>::iterator it2 = mstack2.begin(); it2 != mstack2.end(); ++it2) {
        std::cout << *it2 << std::endl;
    }

    return 0;
}
