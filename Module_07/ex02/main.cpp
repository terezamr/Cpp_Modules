#include <iostream>
#include "Array.hpp"

struct Point {
    int x;
    int y;
};

int main(int, char**)
{
    {
        Array<int> f;
        Array<int> numb(3);
        for (int i = 0; i < 3; i++)
            std::cout << "numb: " << numb[i] << std::endl;
        
        try
        {
            std::cout << "numb: " << numb[10] << std::endl;
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
        p[0].x = 1;
        p[0].y = 2;
        p[1].x = 3;
        p[1].y = 4;
        for (int i = 0; i < 2; i++)
            std::cout << "p: " << p[i].x << ", " << p[i].y << std::endl;

        std::cout << "----------" << std::endl;
        Array<std::string> s(3);
        s[0] = "a";
        s[1] = "b";
        s[2] = "c";
        try
        {
            for (int i = 0; i < 3; i++)
                std::cout << "str: " << s[i] << std::endl;
            std::cout << "str: " << s[3] << std::endl;
        }
        catch(const std::exception& error)
        {
            std::cout << error.what() << '\n';
        }
        std::cout << "----------" << std::endl;
        
        const Array<std::string> s2(s);
        std::cout << s2[0] << std::endl;
    }
    // {
    //     std::cout << "\n-----MAIN FROM SUBJECT-----\n" << std::endl;

    //     Array<int> numbers(MAX_VAL);
    //     int* mirror = new int[MAX_VAL];
    //     std::srand(time(NULL));
    //     for (int i = 0; i < MAX_VAL; i++)
    //     {
    //         const int value = std::rand();
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
    //         numbers[i] = std::rand();
    //     }
    //     delete [] mirror;
    // }
    return 0;
}
