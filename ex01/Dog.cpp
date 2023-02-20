#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() 
{
  type_ = "Dog";
  brain_ = new Brain();
  std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal() 
{
  brain_ = NULL;
  *this = copy;
  std::cout << "Copy constructor of Dog called" << std::endl;
}

Dog::~Dog() 
{
  delete this->brain_;
  std::cout << "Destructor of Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) 
{
  this->type_ = src.getType();

  if (this->brain_) delete this->brain_;
  this->brain_ = new Brain(*src.getBrain());

  std::cout << "Assignment Operator of Dog called" << std::endl;
  return (*this);
}

void Dog::makeSound(void) const 
{
  std::cout << "Bark..! Bark...!" << std::endl;
}

Brain *Dog::getBrain() const {
  return brain_;
}