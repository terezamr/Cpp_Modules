#include <iostream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int f = 0; f < str.size(); f++)
				std::cout << (char)toupper(str[f]);
		}
		std::cout << "\n";
	}
	return (0);
}
