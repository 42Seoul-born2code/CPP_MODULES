#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
  this->hp_ = 100;
  this->ep_ = 100;
  this->damage_ = 30;
  std::cout << "[FragTrap] " << "Default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  this->hp_ = 100;
  this->ep_ = 100;
  this->damage_ = 30;
  std::cout << "[FragTrap] " << "Constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) {
  *this = copy;
  std::cout << "[FragTrap] " << "Copy constructor called" << std::endl;
}
FragTrap::~FragTrap() {
  std::cout << "[FragTrap] " << "Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
  this->name_ = src.getName();
  this->hp_ = src.getHp();
  this->ep_ = src.getEp();
  this->damage_ = src.getDamage();
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  if (checkStatus() == DEAD) {
    std::cout << "HighFive Fail : ";
    printStatus();
    return;
  }
  std::cout << "[" << "FragTrap" << "] " << name_
            << " HIGH FIVE !!!!!" << std::endl;
}
