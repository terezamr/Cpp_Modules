#include "Span.hpp"

Span::Span() : N(0), used(0), vec(0)
{
    // std::cout << "Default Constructor" << std::endl;
}

Span::~Span()
{
    // std::cout << "Destructor" << std::endl;
}

Span::Span(unsigned int n) : N(n), used(0), vec(0)
{
    // std::cout << "Constructor" << std::endl;
}

Span::Span(const Span &src)
{
    // std::cout << "Copy assignment" << std::endl;
    if (this != &src)
    {
        this->N = src.N;
        this->used = src.used;
        this->vec = src.vec;
    }
}

Span    &Span::operator=(const Span &src)
{
    // std::cout << "Copy assignment operator" << std::endl;
    if (this != &src)
    {
        this->N = src.N;
        this->used = src.used;
        this->vec = src.vec;
    }
    return *this;
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
        throw(std::exception());
}

long    Span::longestSpan()
{
    if (this->used <= 1)
        throw(std::exception());

    std::sort(this->vec.begin(), this->vec.end());
    long  min = this->vec[0];
    long  max = this->vec[used - 1];

    return (abs(max - min));
}

long    Span::shortestSpan()
{
    if (this->used <= 1)
        throw(std::exception());

    long    diff;
    long    aux;

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
            //int random_value = rand();
            this->vec.push_back(i);
            //std::cout << "Added " << i << std::endl;
            used++;
        }
    }
    else
        throw(std::exception());
}

// std::ostream & operator<<(std::ostream & o, Span const & s)
// {
//     std::vector<int>::iterator i;
//     for (i = s.vec.begin(); i != s.vec.end(); i++)
//         std::cout << *i << std::endl;
//     return o;
// }
