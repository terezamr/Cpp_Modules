#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl joe;
    if (argc != 2)
	{
		std::cout << "Expected one parameter.\n" << std::endl;
        return (0);
	}
    std::string input = argv[1];
    const char* levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && input != levels[i])
        i++;
    if (i == 4)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    for (int f = i; f < 4; f++)
    {
        switch (f) {
            case 0:
                joe.complain("DEBUG");
                break;
            case 1:
                joe.complain("INFO");
                break;
            case 2:
                joe.complain("WARNING");
                break;
            case 3:
                joe.complain("ERROR");
                break;
        }
    }
}
