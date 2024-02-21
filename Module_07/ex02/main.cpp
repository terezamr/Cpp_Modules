#include <iostream>
#include "Array.hpp"

struct Point {
    int x;
    int y;
};

#define MAX_VAL 750
int main(int, char**)
{
    {
        Array<int> f;
        Array<int> numb(4);
        for (int i = 0; i < 2; i++)
            std::cout << "numb: " << numb[i] << std::endl;
        
        try
        {
            numb[10];
        }
        catch(const std::exception& error)
        {
            std::cout << error.what() << '\n';
        }
        std::cout << "----------" << std::endl;

        for (int f = 0; f < 3; f++)
            numb[f] = f + 1;

        Array<int> a(numb);
        Array<int> b;
        b = numb;
        for (int i = 0; i < 3; i++)
        {
            std::cout << "a: " << a[i] << std::endl;
            std::cout << "b: " << b[i] << std::endl;
        }
        
        std::cout << "----------" << std::endl;

        for (int i = 0; i < 3; i++)
        {
            numb[i] = i + 5;
            std::cout << "a: " << a[i] << std::endl;
        }

        for (int i = 0; i < 3; i++)
        {
            a[i] = i + 10;
            std::cout << "n: " << numb[i] << std::endl;
        }

        std::cout << "----------" << std::endl;

        std::cout << "size n: " << numb.size() << std::endl;
        std::cout << "size a: " << a.size() << std::endl;

        std::cout << "----------" << std::endl;

        Array<Point> p(2);
        p[0] = {1, 2};
        p[1] = {3, 4};
        for (int i = 0; i < 2; i++)
            std::cout << "p: " << p[i].x << ", " << p[i].y << std::endl;
    }
    // {
    //     std::cout << "\n-----MAIN FROM SUBJECT-----\n" << std::endl;

    //     Array<int> numbers(MAX_VAL);
    //     int* mirror = new int[MAX_VAL];
    //     srand(time(NULL));
    //     for (int i = 0; i < MAX_VAL; i++)
    //     {
    //         const int value = rand();
    //         numbers[i] = value;
    //         mirror[i] = value;
    //     }
    //     //SCOPE
    //     {
    //         Array<int> tmp = numbers;
    //         Array<int> test(tmp);
    //     }

    //     for (int i = 0; i < MAX_VAL; i++)
    //     {
    //         if (mirror[i] != numbers[i])
    //         {
    //             std::cerr << "didn't save the same value!!" << std::endl;
    //             return 1;
    //         }
    //     }
    //     std::cout << "Success!" << std::endl;
    //     try
    //     {
    //         numbers[-2] = 0;
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    //     try
    //     {
    //         numbers[MAX_VAL] = 0;
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }

    //     for (int i = 0; i < MAX_VAL; i++)
    //     {
    //         numbers[i] = rand();
    //     }
    //     delete [] mirror;
    // }
    return 0;
}