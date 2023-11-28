#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b;
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	//a.setRawBits(2);
	//std::cout << a.getRawBits() << std::endl;
	//Fixed d (a);
	//std::cout << d.getRawBits() << std::endl;
	return 0;
}
