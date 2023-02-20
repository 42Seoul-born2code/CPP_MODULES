#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = (num << this->fBits_);
}

/*
	float에 바로 비트 연산을 할 수 없기 때문에 1<< 8 을 한 값을 곱해준다.
	roundf 함수는 x값에 가장 가까운 정수를 나타내는 부동 소수점 값을 반환한다.
*/

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(num * (1 << this->fBits_));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = fixed.getRawBits();
	return (*this);
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