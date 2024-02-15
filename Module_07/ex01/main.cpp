#include "Iter.hpp"

// Array passed as a pointer: This means that changes made to the array inside the iter function could affect the
// original array if you're modifying the array itself (like reassigning elements).

// Array elements passed by reference: When calling the function pointer func, it takes the array elements by
// reference. This means that the function pointer operates directly on the original array elements, and any
// modifications made to them will affect the original array.

// check void (*func)(T const&)

int main(void)
{
    {
        int a[3] = {5, 6, 7};
        iter(a, 3, increment);
        iter(a, 3, print_value);

        std::string b[3] = {"five", "six", "seven"};
        iter(b, 3, print_value);

        float c[3] = {1.3, 2432.4, -56.94};
        iter(c, 3, print_value);

        int d[3] = {'\0'};
        iter(d, 3, print_value);
    }
    {
        int tab[] = {0, 1, 2, 3, 4};
        Awesome tab2[5];
        iter(tab, 5, print);
        iter(tab2, 5, print);
    }
    return 0;
}