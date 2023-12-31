#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb << this->Bits);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(nb * ((1 << this->Bits))));
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// The copy assignment operator takes a constant reference to
// another object of the same class and copies it
Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

// Converts fixed-point rep. into a floating-point rep.
float   Fixed::toFloat(void) const
{
    return (float)(this->getRawBits()) / (1 << this->Bits);
}

// Converts fixed-point rep. into an integer rep.
int     Fixed::toInt(void) const {
    return (this->getRawBits() >> this->Bits);
}

// Defines how an object of the Fixed class should be formatted when printed
// By calling the toFloat() method, ensures that the Fixed value is
// displayed as a floating-point number (used in main)
std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
