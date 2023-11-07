#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed( 5.05f ) - Fixed( 6 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	// std::cout << --a << std::endl;
	// std::cout << a-- << std::endl;
	// std::cout << a << std::endl;
	// std::cout << --a << std::endl;

	std::cout << b << std::endl;
	// if (a < b)
	// 	std::cout << "a smaller than b" << std::endl;
	// if (a > b)
	// 	std::cout << "a greater than b" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}