#include <iostream>
#include "Fixed.hpp"

/*
	1/256 = 0.0390625

	0.0390625 * 2 = 0.0078125

	float계산에서 오차가 생겨서 10.1016 처럼 뒤에 소수점 자리 오차가 발생할 수 있음
*/
int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}