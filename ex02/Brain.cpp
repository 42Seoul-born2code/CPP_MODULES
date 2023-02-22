#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) 
{
  for (int i = 0; i < 100; i++) {
    this->ideas_[i] = "idea";
  }
  std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::Brain(const Brain &copy) 
{
  *this = copy;
  std::cout << "Copy constructor of Brain called" << std::endl;
}

Brain::~Brain() 
{
  std::cout << "Destructor of Brain called" << std::endl;
}


Brain &Brain::operator=(const Brain &src) 
{
  for (int i = 0; i < 100; i++) {
    this->ideas_[i] = src.ideas_[i];
  }
  std::cout << "Assignment Operator of Brain called" << std::endl;
  return (*this);
}

const std::string *Brain::getIdeas() const 
{
  return ideas_;
}

void Brain::setIdea(int index, std::string idea) {
  this->ideas_[index] = idea;
}