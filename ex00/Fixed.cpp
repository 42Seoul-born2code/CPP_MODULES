#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPoint_ = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPoint_;
}
void Fixed::setRawBits(const int raw) {
  std::cout << "getRawBits member function called" << std::endl;
  this->fixedPoint_ = raw;
}

Fixed::~Fixed() {
  std::cout << "Destructor called " << std::endl;
}