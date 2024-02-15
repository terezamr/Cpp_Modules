#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {
        Array<int> numb(3);
        int* copy = new int[3];

        std::cout << "copy 0: " << *copy << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << "numb: " << numb[i] << std::endl;
            std::cout << "copy: " << copy[i] << std::endl;
            std::cout << "----------" << std::endl;
        }

        for (int f = 0; f < 3; f++)
            numb[f] = f;

        // copy assignment
        Array<int> a(numb);
        for (int i = 0; i < 3; i++)
            std::cout << "a: " << a[i] << std::endl;

        // copy assigment operator
        Array<int> b;
        b = numb;
        for (int i = 0; i < 3; i++)
            std::cout << "b: " << b[i] << std::endl;
        
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
        delete [] copy;
    }
    {
        std::cout << "\n-----MAIN FROM INTRA-----\n" << std::endl;

        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        std::cout << "Success!" << std::endl;
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }
    return 0;
}