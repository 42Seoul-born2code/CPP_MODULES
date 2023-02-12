#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
 private:
  int fixedPoint_;
  static const int fBits_ = 8;

 public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
};

#endif 