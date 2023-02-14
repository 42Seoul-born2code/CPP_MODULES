#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	ct1("ct1");
	ClapTrap	ct2("ct2");

	ct1.printStatus();
	ct2.printStatus();

	ct1.setDamage(5);
	ct1.attack(ct2.getName());
	ct1.printStatus();
	ct2.printStatus();
	ct2.takeDamage(ct1.getDamage());
	ct2.printStatus();
	ct2.beRepaired(1);
	ct2.printStatus();

	std::cout << "=================================" << std::endl;

	ct1.setDamage(150);
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getDamage());
	ct2.beRepaired(1);
	ct2.printStatus();
}