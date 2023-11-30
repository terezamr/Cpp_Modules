#include "Point.hpp"

Fixed	cross_product(Point const a, Point const b, Point const c)
{
	Fixed cp;
	cp = (b.getX() - a.getX()) * (c.getX() - a.getX()) + (b.getY() - a.getY()) * (c.getY() - a.getY());
	std::cout << "conta " << (b.getY() - a.getY()) << std::endl;
	if (cp < 0)
		cp = cp * -1;
	std::cout << "cp  " << cp << std::endl;
	return (cp);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A1;
	Fixed A2;
	Fixed A3;
	Fixed A;

	A = cross_product(a, b, c) / 2;
	A1 = cross_product(a, b, point) / 2;
	A2 = cross_product(a, point, c) / 2;
	A3 = cross_product(point, b, c) / 2;
	std::cout << "A " << A << std::endl;
	std::cout << "A1 " << A1 << std::endl;
	std::cout << "A2 " << A2 << std::endl;
	std::cout << "A3 " << A3 << std::endl;
	if (A1 + A2 + A3 == A)
	{
		std::cout << "belongs" << std::endl;
		return true;
	}
	std::cout << "doesnt belong" << std::endl;
	return (false);
}