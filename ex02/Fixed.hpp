#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fBits_ = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &fixed);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;

		Fixed	&operator= (const Fixed &fixed);

		bool	operator> (const Fixed &fixed);
		bool	operator< (const Fixed &fixed);
		bool	operator>= (const Fixed &fixed);
		bool	operator<= (const Fixed &fixed);
		bool	operator== (const Fixed &fixed);
		bool	operator!= (const Fixed &fixed);

		Fixed	operator+ (const Fixed &fixed);
		Fixed	operator- (const Fixed &fixed);
		Fixed 	operator* (const Fixed &fixed);
		Fixed	operator/ (const Fixed &fixed);

		Fixed&	operator++ ();
		Fixed	operator++ (int);
		Fixed&	operator-- ();
		Fixed	operator-- (int);

		static Fixed&			min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&		min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&			max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&		max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator << (std::ostream& os, const Fixed& fixed);

#endif