#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string target_;
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

  void execute(const Bureaucrat &executor) const;
};

#endif 