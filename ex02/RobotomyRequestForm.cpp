#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

// Constructor & Destructor
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {
  std::cout << "Default Constructor of RobotomyRequestForm called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45) {
  this->target_ = target;
  std::cout << "Constructor of RobotomyRequestForm(target) called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form("RobotomyRequestForm",
                                                                                 72,
                                                                                 45) {
  this->target_ = copy.target_;
  std::cout << "Copy Constructor of RobotomyRequestForm called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
}

// Operator Overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  this->target_ = src.target_;
  return (*this);
}

// Method
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  Form::execute(executor);
  std::cout << target_ << " has been robotomized successfully 50% of the time" << std::endl;
}
