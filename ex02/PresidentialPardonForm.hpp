#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target_;
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

  void execute(const Bureaucrat &executor) const;
};

#endif