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
        // std::cout << "Added " << a << std::endl;
        used++;
    }
    else
        throw(NotValid());
}

int Span::longestSpan()
{
    if (this->used <= 1)
        throw(NotValid());

    std::sort(this->vec.begin(), this->vec.end());
    return (abs(this->vec[0] - this->vec[used - 1]));
}

int Span::shortestSpan()
{
    if (this->used <= 1)
        throw(NotValid());

    int diff;
    int aux;

    std::sort(this->vec.begin(), this->vec.end());
    diff = abs(this->vec[0] - this->vec[1]);

    for (unsigned int i = 1; i < used - 1; i++)
    {
        aux = abs(this->vec[i] - this->vec[i + 1]);
        if (aux < diff)
            diff = aux;
    }
    return (diff);
}

void    Span::addNumbers(unsigned int a)
{
    if (a < N - used)
    {
        for (unsigned int i = 0; i < a; i++)
        {
            int random_value = rand();
            this->vec.push_back(random_value);
            // std::cout << "Added " << random_value << std::endl;
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
