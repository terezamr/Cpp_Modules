#include "Point.hpp"

Point::Point()
{
	(Fixed) x = 0;
	(Fixed) y = 0;
}

Point::Point(const float a, const float b) : x(a), y(b)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point& src) : x(src.getX()), y(src.getY())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Point::~Point()
{
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Point&  Point::operator=( const Point &src ) {
    if (this != &src )
	{
        (Fixed) this->x = src.getX();
        (Fixed) this->y = src.getY();
    }
    return *this;
}
