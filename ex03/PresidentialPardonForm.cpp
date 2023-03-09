#include <iostream>
#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "Default Constructor of PresidentialPardonForm called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5) {
  this->target_ = target;
  std::cout << "Constructor of PresidentialPardonForm(target) called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm",
                                                                                          25,
                                                                                          5) {
  this->target_ = copy.target_;
  std::cout << "Copy Constructor of PresidentialPardonForm called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
}

// Operator Overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  this->target_ = src.target_;
  return (*this);
}

// Method
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!this->isSigned_) throw NotSignedException();
  if (executor.getGrade() > executeGrade_) throw GradeTooLowException();
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}