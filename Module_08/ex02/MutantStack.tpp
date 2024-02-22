#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    //std::cout << "MT constructor" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    //std::cout << "MT destructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>()
{
    //std::cout << "MT copy assigment" << std::endl;
    *this = src;
}

#endif