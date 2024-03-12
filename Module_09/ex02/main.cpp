#include "PmergeMe.hpp"

// '4' '3 5 3'
// 4
// 'a 4' '3a
// b 3
// '' 3
// empty
// tempo depois de guardar o vetor / lista
// numeros negativos?
// forma canonica
// transformar numeros

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
            PmergeMe obj(argv);
            std::cout << "\nBefore: ";
            obj.print(obj.getV());

            clock_t start = clock();
            obj.FordJohnson_vec();
            clock_t time = static_cast<float>(clock() - start) / CLOCKS_PER_SEC * 1000;

            std::cout << "After: ";
            obj.print(obj.getV());
            std::cout << "Time to process with vector: " << time << std::setprecision(10) << " ms.\n" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // {
    //     try
    //     {
    //         PmergeMe obj(argv);
    //         time_t start, end;
    //         time(&start);
    //         this->FordJohnson_dq();
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
