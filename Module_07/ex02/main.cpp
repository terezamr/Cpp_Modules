#include "Array.hpp"

int main(void)
{
    Array< int> a;
    Array< int> b(3);

    int i = 0;
    while (i < 3)
    {
        b[i] = i + 1;
        i++;
    }
    //int *a = new int();
    //display *a;
    return 0;
}