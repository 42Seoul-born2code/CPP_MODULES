#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string &name) : name(name) {}
Zombie::~Zombie(void)
{
	std::cout << name << " Destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	Zombie::name = name;
}
