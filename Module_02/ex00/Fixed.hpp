#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Fixed {
	private:
		int					FixedPoint;
		static const int	Bits = 9;
	public:
		Fixed();
    	~Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif