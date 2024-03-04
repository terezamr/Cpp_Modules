#include "RPN.hpp"

// division by 0 
// more than one space/tab
// no space between chars
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }
    RPN rpn;
    std::string s = argv[1];
    rpn.run(s);

    return 0;
}
