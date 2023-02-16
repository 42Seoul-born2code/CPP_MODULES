#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type_("animal") 
{
  std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type_(copy.getType()) 
{
  std::cout << "Copy constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
  std::cout << "Destructor of WrongAnimal called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of WrongAnimal called" << std::endl;
  return (*this);
}

void WrongAnimal::makeSound(void) const 
{
  std::cout << "Don't have sound yet..." << std::endl;
}

const std::string &WrongAnimal::getType() const 
{
  return type_;
}