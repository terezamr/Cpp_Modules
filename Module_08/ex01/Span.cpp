#include "Span.hpp"

Span::Span(unsigned int n) : N(n), used(0)
{
    // std::cout << "Constructor" << std::endl;
}

void    Span::addNumber(int a)
{
    if (used < N)
    {
        this->vec.push_back(a);
        std::cout << "Added " << a << std::endl;
        used++;
    }
    else
        throw(NotValid());
}

int Span::longestSpan()
{
    int min;
    int max;
    if (this->used <= 1)
        throw(NotValid());
    std::vector<int>::iterator i;

    min = *this->vec.begin();
    for (i = this->vec.begin(); i != this->vec.end(); i++)
    {
        if (min > *i)
            min = *i;
    }

    max = *this->vec.begin();
    for (i = this->vec.begin(); i != this->vec.end(); i++)
    {
        if (max < *i)
            max = *i;
    }
    return (abs(max - min));
}

int Span::shortestSpan()
{
    if (this->used <= 1)
        throw(NotValid());

    std::vector<int>::iterator i;
    std::vector<int>::iterator aux;
    i = this->vec.begin();
    aux = i;
    i++;
    
    int min = abs(vec[1] - vec[0]);
    int diff;
    for (i; i < this->vec.end(); i++)
    {
        diff = abs(*i - *aux);
        if (diff < min)
            min = diff;
        aux = i;
    }
    return (min);
}

void    Span::addNumbers(int a)
{
    if (a < N - used)
    {
        for (int i = 0; i < a; i++)
        {
            int random_value = std::rand();
            this->vec.push_back(random_value);
            std::cout << "Added " << random_value << std::endl;
            used++;
        }
    }
    else
        throw(NotValid());
}

// std::ostream & operator<<(std::ostream & o, Span const & s)
// {
//     std::vector<int>::iterator i;
//     for (i = s.vec.begin(); i != s.vec.end(); i++)
//         std::cout << *i << std::endl;
//     return o;
// }
