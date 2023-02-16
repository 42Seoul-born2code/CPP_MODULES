#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void) : WrongAnimal() 
{
  type_ = "WrongDog";
  std::cout << "Default constructor of WrongDog called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal() 
{
  *this = copy;
  std::cout << "Copy constructor of WrongDog called" << std::endl;
}

WrongDog::~WrongDog() 
{
  std::cout << "Destructor of WrongDog called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of WrongDog called" << std::endl;
  return (*this);
}

void WrongDog::makeSound(void) const 
{
  std::cout << "Meow..! Meow...!" << std::endl;
}