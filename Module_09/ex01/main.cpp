#include "RPN.hpp"

// more than one space/tab + spaces at begin and end (try sstream)
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }

    RPN rpn;
    std::string s = argv[1];
    try
    {
        rpn.run(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
 