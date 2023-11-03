#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>

class Fixed {
	private:
		int					FixedPoint;
		static const int	Bits = 8;
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
    	~Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& src);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float   toFloat( void ) const;
   		int     toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif