#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() 
{
  type_ = "Dog";
  std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal() 
{
  *this = copy;
  std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog::~Dog() 
{
  std::cout << "Destructor of Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of Dog called" << std::endl;
  return (*this);
}

void Dog::makeSound(void) const 
{
  std::cout << "Bark..! Bark...!" << std::endl;
}