#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type_(type) {}
Weapon::~Weapon() {}

/*
	앞에 붙는 const는 변할 수 없는 상수를 뜻함
	뒤에 붙는 const는 이 함수 내에서는 어떠한 변수도 바뀔 수 없음을 나타냄
	const가 붙은 함수 내에서는 const가 붙은 다른 함수를 제외한 일반 함수는 호출하지 못한다.
*/

const std::string &Weapon::getType() const
{
	return type_;
}

void Weapon::setType(const std::string &type)
{
	Weapon::type_ = type;
}