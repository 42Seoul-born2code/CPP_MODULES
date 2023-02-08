#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string name)
{
	Zombie *zb;

	zb = new Zombie[N];
	for (int i = 0; i < N ; i++)
		zb[i].SetName(name);
	return zb;
}