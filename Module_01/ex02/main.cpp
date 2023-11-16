#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	// stringPTR - pointer variable, stores the address of str
	std::string	*stringPTR = &str;
	// stringREF - reference to str
	std::string &stringREF = str;

	// memory address of str
	std::cout << &str << std::endl;
	// memory addres stringPTR
	std::cout << stringPTR << std::endl;
	// memory addres stringREF
	std::cout << &stringREF << std::endl;

	// The value of the string variable.
	std::cout << str << std::endl;
	// The value pointed to by stringPTR.
	std::cout << *stringPTR << std::endl;
	// The value pointed to by stringREF.
	std::cout << stringREF << std::endl;
}
