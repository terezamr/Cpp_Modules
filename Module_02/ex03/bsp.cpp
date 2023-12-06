#include "Point.hpp"

Fixed	cross_product(Point const a, Point const b, Point const c)
{
	Fixed cp;
	cp = a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - b.getY());
	if (cp < 0)
		cp = cp * -1;
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
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false;
	if (A1 + A2 + A3 == A)
		return true;
	return (false);
}
