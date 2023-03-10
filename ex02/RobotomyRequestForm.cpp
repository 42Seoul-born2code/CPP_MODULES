#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "Default Constructor of RobotomyRequestForm called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45) {
  this->target_ = target;
  std::cout << "Constructor of RobotomyRequestForm(target) called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm",
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
  if (!this->isSigned_) throw NotSignedException();
  if (executor.getGrade() > executeGrade_) throw GradeTooLowException();
  srand(time(nullptr));
  int val = rand() % 2;
  if (val == 1) {
    std::cout << getName() << " : Robotomize success" <<std::endl;
  } else {
    std::cout << getName() << " Robotomize failed..." << std::endl;
  }
}
