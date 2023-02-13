#include "Fixed.hpp"

/*
	a 객체 생성
	b 객체는 a를 복사 생성
	c 객체는 대입 연산자 오버로딩 b를 복사
*/
int main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}