#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name_("untitled"), isSigned_(false), signGrade_(150), executeGrade_(150) {
  std::cout << "Default Constructor of Form called" << std::endl;
}
Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
  if (signGrade_ < 1 || executeGrade_ < 1) throw GradeTooHighException();
  if (signGrade_ > 150 || executeGrade_ > 150) throw GradeTooLowException();
  std::cout << "Constructor of Form(name, signedGrade, executeGrade) called" << std::endl;
}
Form::Form(const Form &copy)
    : name_(copy.name_), isSigned_(false), signGrade_(copy.signGrade_), executeGrade_(copy.executeGrade_) {
  std::cout << "Copy Constructor of Form called" << std::endl;
}
Form::~Form() {
  std::cout << "Destructor of Form called" << std::endl;
}

Form &Form::operator=(const Form &src) {
  this->isSigned_ = src.isSigned_;
  std::cout << "Assignment Operator of Form called" << std::endl;
  return (*this);
}
std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form (name: " << form.getName()
     << ", isSigned: " << (form.IsSigned() ? "true" : "false")
     << ", signGrade: " << form.getSignGrade()
     << ", executeGrade: " << form.getExecuteGrade() << ")";
  return (os);
}

const std::string &Form::getName() const {
  return name_;
}
bool Form::IsSigned() const {
  return isSigned_;
}
int Form::getSignGrade() const {
  return signGrade_;
}
int Form::getExecuteGrade() const {
  return executeGrade_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (this->isSigned_) throw SignedAlreadyException();
  if (bureaucrat.getGrade() > signGrade_) throw GradeTooLowException();
  isSigned_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade Too High";
}
const char *Form::GradeTooLowException::what() const throw() {
  return "Grade Too Low";
}
const char *Form::SignedAlreadyException::what() const throw() {
  return "Signed Already";
}