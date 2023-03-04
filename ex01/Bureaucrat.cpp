#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name_("noname"), grade_(150) {
  std::cout << "Default Constructor of Bureaucrat called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {
  if (grade_ < 1) throw GradeTooHighException();
  else if (grade_ > 150) throw GradeTooLowException();
  std::cout << "Constructor of Bureaucrat(name, grade) called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name_(copy.name_), grade_(copy.grade_) {
  std::cout << "Copy Constructor of Bureaucrat called" << std::endl;
}
Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor of Bureaucrat called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  this->grade_ = src.getGrade();
  std::cout << "Assignment Operator of Bureaucrat called" << std::endl;
  return (*this);
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade "
     << bureaucrat.getGrade() << ".";
  return (os);
}

const std::string &Bureaucrat::getName() const {
  return name_;
}
int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << name_ << " couldn't sign " << form.getName()
              << ", because " << e.what() << std::endl;
  }
}
void Bureaucrat::incrementGrade() {
  if (grade_ <= 1) throw GradeTooHighException();
  grade_--;
}
void Bureaucrat::decrementGrade() {
  if (grade_ >= 150) throw GradeTooLowException();
  grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Error: Grade Too High";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Error: Grade Too Low";
}