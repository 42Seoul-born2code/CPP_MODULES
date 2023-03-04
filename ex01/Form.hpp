#ifndef FORM_HPP_
#define FORM_HPP_

#include <string>

class Bureaucrat;
class Form {
 private:
  const std::string name_;
  bool isSigned_;
  const int signGrade_;
  const int executeGrade_;
 public:
  Form();
  Form(const std::string &name, const int signGrade, const int executeGrade);
  Form(const Form &copy);
  ~Form();

  Form &operator=(const Form &src);

  const std::string &getName() const;
  bool IsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif