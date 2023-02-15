#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  ScavTrap st1("ST1");
  ClapTrap ct1("CT1");
  FragTrap ft1("FT1");

  st1.printStatus();
  ct1.printStatus();

  st1.setDamage(5);
  st1.attack(ct1.getName());
  ct1.takeDamage(st1.getDamage());
  st1.printStatus();
  ct1.printStatus();

  std::cout << "----------------------------------------" << std::endl;

  ct1.beRepaired(1);
  ct1.printStatus();

  std::cout << "----------------------------------------" << std::endl;

  st1.setDamage(150);
  st1.attack(ct1.getName());
  ct1.takeDamage(st1.getDamage());
  st1.printStatus();
  ct1.printStatus();

  ct1.beRepaired(1);
  ct1.printStatus();

  st1.guardGate();
  ct1.attack(st1.getName());

  std::cout << "----------------------------------------" << std::endl;

  ft1.printStatus();
  ft1.attack(st1.getName());
  st1.takeDamage(ft1.getDamage());
  st1.printStatus();
  ft1.printStatus();
  st1.beRepaired(10);
  st1.printStatus();

  ft1.highFivesGuys();

  return 0;
}