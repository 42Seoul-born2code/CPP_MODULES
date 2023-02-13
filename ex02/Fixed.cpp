#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedPoint= 0;
}

Fixed::Fixed(const int num)
{
	this->fixedPoint = (num << this->fBits_);
}

Fixed::Fixed(const float num)
{
	this->fixedPoint = roundf(num * (1 << this->fBits_));
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed &fixed)
{
	this->fixedPoint = fixed.getRawBits();
}

Fixed&	Fixed::operator= (const Fixed &fixed)
{
	this->fixedPoint = fixed.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator++ ()
{
	this->fixedPoint++;

	return (*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed	newFixed(*this);

	this->fixedPoint++;
	return (newFixed);
}

Fixed&	Fixed::operator-- ()
{
	this->fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed	newFixed(*this);
	this->fixedPoint--;
	return (newFixed);
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->getRawBits() > fixed.getRawBits());
} 

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	newFixed(this->toFloat() + fixed.toFloat());
	return (newFixed);
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	newFixed(this->toFloat() - fixed.toFloat());

	return (newFixed);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	newFixed(this->toFloat() * fixed.toFloat());

	return (newFixed);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	newFixed(this->toFloat() / fixed.toFloat());

	return (newFixed);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

float	Fixed::toFloat(void)const
{
	return ((float)this->fixedPoint / (1 << this->fBits_));
}

int		Fixed::toInt(void)const
{
	return (this->fixedPoint >> this->fBits_);
}

int	Fixed::getRawBits(void)const
{
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}