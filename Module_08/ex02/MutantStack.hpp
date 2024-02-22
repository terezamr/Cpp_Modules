#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &src);

        class iterator : public std::stack<T>::container_type::iterator 
        {
            public:
                iterator() : std::stack<T>::container_type::iterator() {}
                iterator(typename std::stack<T>::container_type::iterator it) : std::stack<T>::container_type::iterator(it) {}
    
        };

        iterator begin()
        {
            return iterator(this->c.begin());
        }

        iterator end()
        {
            return iterator(this->c.end());
        }
};

#include "MutantStack.tpp"

#endif