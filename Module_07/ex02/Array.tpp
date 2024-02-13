#ifndef ARRAY_TPP
#define ARRAY_TPP

// construction with no parameter
template <class T>
Array<T>::Array(void) : len(0), arr(nullptr)
{
    std::cout << "Array constructor called" << std::endl;
}

// construction with int n as parameter
template <class T>
Array<T>::Array(unsigned int n) : len(n)
{
    std::cout << "Array constructor called" << std::endl;
    this->arr = new T[n];
}

// Construction by copy

// Assignment operator.

// [] Operator
template <class T>
T &Array<T>::operator [](int n)
{
    if (n < this->len)
        return arr[n];
    else
        throw std::invalid_argument("Received negative value");
}

#endif