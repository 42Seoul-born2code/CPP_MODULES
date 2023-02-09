#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
{
	name_ = name;
	weapon_ = NULL;
}
HumanB::~HumanB() {}

void HumanB::attack()
{
	if (!weapon_)
	{
		std::cout << name_ << " does not have weapon..." << std::endl;
		return ;
	}
	std::cout << name_ << " attacks with their" << (*weapon_).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}