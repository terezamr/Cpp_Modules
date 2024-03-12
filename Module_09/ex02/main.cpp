#include "PmergeMe.hpp"

// '4' '3 5 3'
// 4
// 'a 4' '3a
// b 3
// '' 3
// empty
// tempo depois de guardar o vetor / lista
// numeros negativos?

// first pairs of elements are compared; in the second step the larger elements are sorted recursively; as a last step the elements belonging to the smaller half are inserted into the already sorted larger half using binary insertion.
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Bad input" << std::endl;
        return 1;
    }
    // {
    //     try
    //     {
    //         time_t start, end;
    //         time(&start);
    //         PmergeMe obj1(argv, 1);
    //         time(&end);

    //         obj1.print_l();
    //         std::cout << "Time to process with list: " << obj1.getTime() << std::setprecision(20) << " ms." << std::endl;
    //         std::cout << "\n";
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    // }
    {
        try
        {
            std::cout << "\n";
            //time_t start, end;
            clock_t start = clock();
            //time(&start);
            PmergeMe obj(argv);
            //time(&end);

            obj.print_v();
            //std::cout << "Time to process with vector: " << obj.getTime() << std::setprecision(10) << " ms." << std::endl;
            std::cout << static_cast<float>(clock() - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // {
    //     try
    //     {
    //         time_t start, end;
    //         time(&start);
    //         PmergeMe obj2(argv, argv[1]);
    //         time(&end);

    //         obj2.print_dq();
    //         std::cout << "Time to process with deque: " << obj2.getTime() << std::setprecision(20) << " ms." << std::endl;
    //         std::cout << "\n";
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    // }
    return 0;
}
