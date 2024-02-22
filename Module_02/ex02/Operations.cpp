#include "Fixed.hpp"

// + - * /
Fixed Fixed::operator+(Fixed const &a)
{
    return (this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(Fixed const &a)
{
    return (this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(Fixed const &a)
{
    return (this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(Fixed const &a)
{
    return (this->toFloat() / a.toFloat());
}

// ++ --
Fixed Fixed::operator++(void)
{
    ++this->FixedPoint;
    return (*this);
}

Fixed Fixed::operator++(int nb)
{
    Fixed tmp(*this);
    ++this->FixedPoint;
    (void)nb;
    return (tmp);
}

Fixed Fixed::operator--(void)
{
    --this->FixedPoint;
    return (*this);
}

Fixed Fixed::operator--(int nb)
{
    Fixed tmp(*this);
    --this->FixedPoint;
    (void)nb;
    return (tmp);
}

// > < >= <= == !=
bool    Fixed::operator>(const Fixed &rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed &rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool    Fixed::operator>=(const Fixed &rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed &rhs) const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed &rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed &rhs) const {
    return (this->getRawBits() != rhs.getRawBits());
}

// min max
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
