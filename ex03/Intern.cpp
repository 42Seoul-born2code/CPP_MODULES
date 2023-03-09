#include <iostream>
#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Default Constructor of Intern called" << std::endl;
}
Intern::Intern(const Intern &copy) {
  (void) copy;
  std::cout << "Copy Constructor of Intern called" << std::endl;
}
Intern::~Intern() {
  std::cout << "Destructor of Intern called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
  (void) src;
  return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}
AForm *Intern::makeForm(std::string name, std::string target) {
  const std::string nameList[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
  AForm *(Intern::*fp[3])(std::string target) = {&Intern::makeShrubberyCreationForm,
                                                &Intern::makeRobotomyRequestForm,
                                                &Intern::makePresidentialPardonForm};
  AForm *res = NULL;

  for (int i = 0; i < 3; i++) {
    if (nameList[i] == name) {
      res = (this->*fp[i])(target);
      break;
    }
  }
  if (res == NULL) throw UnknownFormException();
  std::cout << "Intern creates " << name << std::endl;
  return (res);
}

const char *Intern::UnknownFormException::what() const throw() {
  return "Error: Unknown Form name is given";
}