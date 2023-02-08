#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string &name) : name(name) {}
Zombie::~Zombie()
{
	std::cout << name << ": Destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}