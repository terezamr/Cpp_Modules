#ifndef ARRAY_TPP
#define ARRAY_TPP

// construction with no parameter
template <typename T>
Array<T>::Array(void) : len(0), arr(0)
{
    //std::cout << "Array constructor called" << std::endl;
}

// construction with int n as parameter
template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
    //std::cout << "Array constructor called" << std::endl;
    if (static_cast<int>(n) < 0)
        throw(NotValid());
    else if (static_cast<int>(n) == 0)
    {
        this->len = 0;
        this->arr = 0;
    }
    else
    {
        this->arr = new T[n];
        for (unsigned int i = 0; i < n; ++i)
            this->arr[i] = T(); // Default initialization for type T
    }
}

// Construction by copy
template <typename T>
Array<T>::Array(const Array& src) : len(src.len)
{
    //std::cout << "Copy assigment." << std::endl;
    this->arr = new T[src.len];
    for (unsigned int i = 0; i < this->len; i++)
        this->arr[i] = src.arr[i];
}

// Assignment operator.
template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
    //std::cout << "Copy assigment operator." << std::endl;
    if (this != &src)
    {
        if (this->array)
            delete [] this->arr;
        this->arr = new T[src.len];
        this->len = src.len;
        for (unsigned int i = 0; i < len; i++)
            this->arr[i] = src.arr[i];
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array(void)
{
    //std::cout << "Array destructor called" << std::endl;
    if (this->arr)
        delete [] this->arr;
}

template <typename T>
int Array<T>::size()
{
    return (this->len);
}

// [] Operator
template <typename T>
T &Array<T>::operator [](unsigned int n) const
{
    if (n < this->len)
        return arr[n];
    else
        throw(NotValid());
}

#endif
