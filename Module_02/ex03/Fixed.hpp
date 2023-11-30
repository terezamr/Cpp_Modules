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
		Fixed&	operator=(const Fixed& src);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float   toFloat(void) const;
   		int     toInt(void) const;

		Fixed	operator+(Fixed const &a);
		Fixed	operator-(Fixed const &a);
		Fixed	operator*(Fixed const &a);
		Fixed	operator/(Fixed const &a);

		Fixed	operator++(void);
		Fixed	operator++(int nb);
		Fixed	operator--(void);
		Fixed	operator--(int nb);

		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool    operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool    operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

	// A static member function can be called even if no objects of the class exist
		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif