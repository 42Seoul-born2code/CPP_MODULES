#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon) : name_(name), weapon_(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}