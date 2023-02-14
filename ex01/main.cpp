#include "Zombie.hpp"

/*
	길이가 5인 객체 배열을 선언해서 객체를 5개 만들고
	delete[]로 지운다.
	객체 배열의 소멸은 생성의 역순으로 호출한다.
*/
int main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(5, "Horde");
	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}