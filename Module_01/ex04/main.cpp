#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
	{
		std::cout << "Unexpected input" << std::endl;
		return (0);
	}
	replace(argc, argv);
	return (0);
}
