#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type_("animal") 
{
  std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
  type_ = copy.getType();
  std::cout << "Copy constructor of Animal called" << std::endl;
}

Animal::~Animal() 
{
  std::cout << "Destructor of Animal called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of Animal called" << std::endl;
  return (*this);
}

void Animal::makeSound(void) const 
{
  std::cout << "Don't have sound yet..." << std::endl;
}

const std::string &Animal::getType() const 
{
  return type_;
}