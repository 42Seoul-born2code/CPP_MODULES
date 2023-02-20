#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() 
{
  type_ = "Cat";
  brain_ = new Brain();
  std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal() 
{
  brain_ = NULL;
  *this = copy;
  std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat::~Cat() {
  delete this->brain_;
  std::cout << "Destructor of Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) 
{
  this->type_ = src.getType();

  if (this->brain_) delete this->brain_;
  this->brain_ = new Brain(*src.getBrain());

  std::cout << "Assignment Operator of Cat called" << std::endl;
  return (*this);
}

void Cat::makeSound(void) const 
{
  std::cout << "Meow..! Meow...!" << std::endl;
}

Brain *Cat::getBrain() const 
{
  return brain_;
}