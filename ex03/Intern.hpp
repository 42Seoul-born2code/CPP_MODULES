#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern &copy);
  ~Intern();

  Intern &operator=(const Intern &src);

  AForm *makeShrubberyCreationForm(std::string target);
  AForm *makeRobotomyRequestForm(std::string target);
  AForm *makePresidentialPardonForm(std::string target);
  AForm *makeForm(std::string name, std::string target);

  class UnknownFormException : public std::exception {
   public:
    virtual const char *what() const _NOEXCEPT;
  };
};

#endif