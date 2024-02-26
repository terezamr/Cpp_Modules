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
        MutantStack &operator=(const MutantStack &src);

        typedef typename std::stack<T>::container_type::iterator iterator;
	
        iterator begin() {
            return iterator(this->c.begin());
        }

        iterator end() {
            return iterator(this->c.end());
        }
};

#include "MutantStack.tpp"

#endif