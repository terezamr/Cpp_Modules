#include "Fixed.hpp"

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

Fixed Fixed::operator++(void)
{
    ++this->FixedPoint;
    return (*this);
}

Fixed Fixed::operator++(int nb)
{
    Fixed tmp(*this);
    ++this->FixedPoint;
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
    return (tmp);
}

//////////////////////////////////

bool    Fixed::operator>(const Fixed &rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed &rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}