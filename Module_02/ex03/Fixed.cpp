#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int nb)
{
	this->setRawBits(nb << this->Bits);
}

Fixed::Fixed(const float nb)
{
	this->setRawBits(roundf(nb * ((double)(1 << this->Bits))));
}

Fixed::Fixed(const Fixed& src)
{
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this == &src)
		return *this;
	this->setRawBits(src.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (this->FixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
    return (float)(this->getRawBits()) / (1 << Bits);
}

int	Fixed::toInt( void ) const {
    return this->FixedPoint >> Bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
