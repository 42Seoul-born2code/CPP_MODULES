#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target_;
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

  void execute(const Bureaucrat &executor) const;
};

#endif