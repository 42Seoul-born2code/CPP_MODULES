#include "Zombie.hpp"

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