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
			std::string str = std::string(argv[i]);
			for (int f = 0; f < str.size(); f++)
			{
				char c = toupper(str[f]);
				std::cout << c;
			}
		}
		std::cout << "\n";
	}
	return (0);
}
