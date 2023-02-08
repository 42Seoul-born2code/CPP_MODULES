#include "Zombie.hpp"

int main(void)
{
	Zombie *zb;

	zb = ombieHorde(5, "Horde~~");
	for (int i = 0; i < 5; i++)
	{
		zb[i].Announce();
	}
	delete[] zb;
}