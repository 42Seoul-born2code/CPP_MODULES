#include "Zombie.hpp"

/*
	정적 클래스와 동적 클래스의 호출 시점은 다르다.
	정적은 객체를 정의한 함수가 끝날 때때
	동적은 delte 해제
*/

int main(void)
{
	Zombie *zb1 = newZombie("jeongkpa");
	Zombie *zb2 = newZombie("polar");
	zb1->announce();
	zb2->announce();
	randomChump("holy");
	randomChump("rosa");
	delete zb1;
	delete zb2;
	return (0);
}