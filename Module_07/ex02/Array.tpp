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
    for (int i = 0; i < n; ++i)
        this->arr[i] = T(); // Default initialization for type T
}

// Construction by copy
template <class T>
Array<T>::Array(const Array& src) : len(src.len)
{
    std::cout << "Copy assigment." << std::endl;
    this->arr = new T[len];
    for (int i = 0; i < this->len; i++)
        this->arr[i] = src.arr[i];
}

// Assignment operator.
template <class T>
Array<T>& Array<T>::operator=(const Array& src)
{
    std::cout << "Copy assigment operator." << std::endl;
    if (!this->arr)
        this->arr = new T[src.len];
    if (this != &src)
    {
        this->len = src.len;
        for (int i = 0; i < len; i++)
            this->arr[i] = src.arr[i];
    }
    return *this;
}

// Destructor
template <class T>
Array<T>::~Array(void)
{
    std::cout << "Array destructor called" << std::endl;
    delete this->arr;
}

template <class T>
int Array<T>::size()
{
    return (this->len);
}

// [] Operator
template <class T>
T &Array<T>::operator [](int n)
{
    if (n < this->len)
        return arr[n];
    else
        throw(IndexNotValid());
}

#endif