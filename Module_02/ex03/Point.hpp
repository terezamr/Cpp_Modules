#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(float const a, float const b);
    	~Point();
		Point(const Point& src);
		Point&  operator=(const Point &src);
		
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif