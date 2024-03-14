#include "PmergeMe.hpp"

long long getTimeMs() {
    timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * 1000000 + currentTime.tv_usec;
}

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
    try
    {
        PmergeMe obj(argv);

        std::cout << "Before: ";
        obj.print(obj.getV());

        // vector
        long long start_time = getTimeMs();
        obj.FordJohnson_vec();
        long long end_time = getTimeMs();
        
        std::cout << "After: ";
        obj.print(obj.getV());
        std::cout << "Time to process a range with " << obj.getN() << " elements with std::vector: " << end_time - start_time << std::setprecision(20) << " us." << std::endl;

        // deque
        start_time = getTimeMs();
        obj.FordJohnson_dq();
        end_time = getTimeMs();
        std::cout << "Time to process a range with " << obj.getN() << " elements with std::deque: " << end_time - start_time << std::setprecision(20) << " us.\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
