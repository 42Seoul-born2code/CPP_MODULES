#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap st1("ST1");
  ClapTrap ct2("CT1");

  st1.printStatus();
  ct2.printStatus();

  st1.setDamage(5);
  st1.attack(ct2.getName());
  ct2.takeDamage(st1.getDamage());
  st1.printStatus();
  ct2.printStatus();

  ct2.beRepaired(1);
  ct2.printStatus();

  std::cout << "----------------------------------------" << std::endl;

  st1.setDamage(150);
  st1.attack(ct2.getName());
  ct2.takeDamage(st1.getDamage());
  st1.printStatus();
  ct2.printStatus();

  ct2.beRepaired(1);
  ct2.printStatus();

  st1.guardGate();
  ct2.attack(st1.getName());

  return 0;
}