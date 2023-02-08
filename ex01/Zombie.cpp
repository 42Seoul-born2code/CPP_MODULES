#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string &name) : name(name) {}
Zombie::~Zombie(void)
{
	std::cout << this->name << " Zombie deleted" << std::endl;
}

void	Zombie::Announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
	this->name = name;
}
