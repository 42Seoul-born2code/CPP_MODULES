#ifndef FIXED_HPP
# define FIXED_HPP

#include<iostream>
#include<math.h>

class Fixed
{

private:
	int					fixedPoint;
	static const int	fBits_ = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed	&operator=(const Fixed &fixed);
	int		getRawBits(void)const;
	void	setRawBits(int const raw);
	float	toFloat(void)const;
	int		toInt(void)const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif