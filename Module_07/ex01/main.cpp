#include "Iter.hpp"

// test new changes with main from subject
int main(void)
{
    {
        int a[3] = {5, 6, 7};
        iter(a, 3, print_value);

        std::string b[3] = {"five", "six", "seven"};
        iter(b, 3, print_value);

        float c[3] = {1.3, 2432.4, -56.94};
        iter(c, 3, print_value);

        int d[3] = {'\0'};
        iter(d, 3, print_value);
    }
    // {
    //     std::cout << "---------" << std::endl;
    //     int tab[] = {0, 1, 2, 3, 4};
    //     Awesome tab2[5];
    //     iter(tab, 5, print);
    //     iter(tab2, 5, print);
    // }
    return 0;
}
