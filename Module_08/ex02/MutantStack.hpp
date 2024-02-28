#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(const MutantStack &src);

        typedef typename std::stack<T>::container_type::iterator iterator;
	
        // underlying container "c" refers to the actual data struct
        // that holds the elements of the stack
    
        iterator begin() {
            return iterator(this->c.begin());
        }

        iterator end() {
            return iterator(this->c.end());
        }
};

#include "MutantStack.tpp"

#endif