#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name_("untitled"), isSigned_(false), signGrade_(150), executeGrade_(150) {
  std::cout << "Default Constructor of AForm called" << std::endl;
}
AForm::AForm(const std::string &name, const int signGrade, const int executeGrade)
    : name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
  if (signGrade_ < 1 || executeGrade_ < 1) throw GradeTooHighException();
  if (signGrade_ > 150 || executeGrade_ > 150) throw GradeTooLowException();
  std::cout << "Constructor of AForm(name, signedGrade, executeGrade) called" << std::endl;
}
AForm::AForm(const AForm &copy)
    : name_(copy.name_), isSigned_(false), signGrade_(copy.signGrade_), executeGrade_(copy.executeGrade_) {
  std::cout << "Copy Constructor of AForm called" << std::endl;
}
AForm::~AForm() {
  std::cout << "Destructor of AForm called" << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
  this->isSigned_ = src.isSigned_;
  std::cout << "Assignment Operator of AForm called" << std::endl;
  return (*this);
}
std::ostream &operator<<(std::ostream &os, const AForm &Aform) {
  os << "AForm (name: " << Aform.getName()
     << ", isSigned: " << (Aform.IsSigned() ? "true" : "false")
     << ", signGrade: " << Aform.getSignGrade()
     << ", executeGrade: " << Aform.getExecuteGrade() << ")";
  return (os);
}

const std::string &AForm::getName() const {
  return name_;
}
bool AForm::IsSigned() const {
  return isSigned_;
}
int AForm::getSignGrade() const {
  return signGrade_;
}
int AForm::getExecuteGrade() const {
  return executeGrade_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->isSigned_) throw SignedAlreadyException();
  if (bureaucrat.getGrade() > signGrade_) throw GradeTooLowException();
  isSigned_ = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade Too High";
}
const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade Too Low";
}
const char *AForm::SignedAlreadyException::what() const throw() {
  return "Signed Already";
}