#include "PmergeMe.hpp"

// forma canonica

// first pairs of elements are compared; in the second step the larger elements are sorted recursively; as a last step the elements belonging to the smaller half
// are inserted into the already sorted larger half using binary insertion.
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "No arguments provided" << std::endl;
        return 1;
    }
    {
        try
        {
            PmergeMe obj(argv);
            std::cout << "\nBefore: ";
            obj.print(obj.getV());

            // vector
            clock_t start = clock();
            obj.FordJohnson_vec();
            clock_t time = static_cast<float>(clock() - start) / CLOCKS_PER_SEC * 1000000;

            std::cout << "After: ";
            obj.print(obj.getV());
            std::cout << "Time to process a range with " << obj.getN() << " elements with std::vector: " << time << std::setprecision(20) << " us." << std::endl;

            // deque
            // clock_t start_dq = clock();
            // obj.FordJohnson_dq();
            // clock_t time_dq = static_cast<float>(clock() - start_dq) / CLOCKS_PER_SEC * 1000000;
            // std::cout << "Time to process a range with " << obj.getN() << " elements with std::deque: " << time_dq << std::setprecision(20) << " us.\n" << std::endl;
            
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
