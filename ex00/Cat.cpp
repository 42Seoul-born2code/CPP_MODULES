#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() 
{
  type_ = "Cat";
  std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal() 
{
  *this = copy;
  std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat::~Cat() 
{
  std::cout << "Destructor of Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) 
{
  this->type_ = src.getType();
  std::cout << "Assignment Operator of Cat called" << std::endl;
  return (*this);
}

void Cat::makeSound(void) const 
{
  std::cout << "Meow..! Meow...!" << std::endl;
}