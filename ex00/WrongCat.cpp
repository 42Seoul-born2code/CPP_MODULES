#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() 
{
  type_ = "WrongCat";
  std::cout << "Default constructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal() 
{
  *this = copy;
  std::cout << "Copy constructor of WrongCat called" << std::endl;
}

WrongCat::~WrongCat() 
{
  std::cout << "Destructor of WrongCat called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of WrongCat called" << std::endl;
  return (*this);
}

void WrongCat::makeSound(void) const 
{
  std::cout << "Meow..! Meow...!" << std::endl;
}