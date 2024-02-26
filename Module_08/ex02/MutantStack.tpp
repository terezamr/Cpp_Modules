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
    // std::cout << "MT copy assigment" << std::endl;
    *this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    // std::cout << "MT copy assigment operator" << std::endl;
    if (this != &src)
        std::stack<T>::operator=(src);
    return (*this);
}

#endif