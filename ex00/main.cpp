#include "Fixed.hpp"

/*
	a 객체 생성
	b 객체는 a를 복사 생성
	c 객체는 대입 연산자 오버로딩 b를 복사

	(복사 생성자를 따로 구현하지 않은 경우)
	디폴트 복사 생성자는 "얕은 복사(Shallow copy)"를 수행한다.
	즉, 디폴트 복사 생성자에 의해 초기화된 객체는 복사한 객체가 가진 reference와 value 모두 똑같이 가지게 되는 것이다.

	필드에 동적 할당을 받아 초기화되는 변수가 있다면
	디폴트 복사 생성자를 이용하지 않고 사용자가 복사 생성자를 직접 정의하여 깊은 복사(Deep copy)가 일어나도록 해야 한다!

	따라서, 복사 생성자를 직접 정의하여 깊은 복사가 일어나도록 하여 문제를 해결할 수 있다.
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