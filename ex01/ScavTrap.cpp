#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->hp_ = 100;
	this->ep_ = 50;
	this->damage_ = 20;
	std::cout << "[ScavTrap] " << "Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->name_ = name;
	this->hp_ = 100;
	this->ep_ = 50;
	this->damage_ = 20;
	std::cout << "[ScavTrap] " << "Constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "[ScavTrap] " << "Copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] " << "Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
  this->name_ = src.getName();
  this->hp_ = src.getHp();
  this->ep_ = src.getEp();
  this->damage_ = src.getDamage();
  return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (checkStatus() != ALIVE)
	{
		std::cout << "Attack Fail : ";
		printStatus();
		return ;
	}

	this->ep_ -= 1;
	std::cout 	<< "ScavTrap " + name_
				<< " attacks " + target << ", causing "
				<< damage_ << " points of damage!"
				<< std::endl;
}

void ScavTrap::guardGate() {
  if (checkStatus() == DEAD) {
    std::cout << "Guard Fail : ";
    printStatus();
    return;
  }
  std::cout << "[" << "ScavTrap" << "] " << name_
            << " is now in Gate keeper mode" << std::endl;
}