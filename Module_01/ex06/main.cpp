#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl* joe;
    if (argc != 2)
        return (0);
    std::string input = argv[1];
    const char* levels[4] = {"debug", "info", "warning", "error"};
    int i = 0;
    while (i < 4 && input != levels[i])
        i++;
    switch(i) {
        case 0:
            joe->complain("debug");
            break;
        case 1:
            joe->complain("info");
            break;
        case 2:
            joe->complain("warning");
            break;
        case 3:
            joe->complain("error");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }   
	//joe->complain(levels[i]);
}