#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <string>

class Bureaucrat;
class AForm {
 protected:
  const std::string name_;
  bool isSigned_;
  const int signGrade_;
  const int executeGrade_;
 public:
  AForm();
  AForm(const std::string &name, const int signed_grade, const int execute_grade);
  AForm(const AForm &copy);
  virtual ~AForm();

  AForm &operator=(const AForm &src);

  const std::string &getName() const;
  bool IsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class SignedAlreadyException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

 class NotSignedException : public std::exception {
  public:
   virtual const char *what() const throw();
 };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif