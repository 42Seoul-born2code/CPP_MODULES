#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int num_;
  static const int fBits_ = 8;

 public:
	Fixed(void);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &src);
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
};

#endif 