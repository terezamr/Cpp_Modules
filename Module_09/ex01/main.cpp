#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: bad input" << std::endl;
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
