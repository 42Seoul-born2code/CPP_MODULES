#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

/*
signForm 함수 때문에 class Form 전방 선언 사용해야함

앞선 과제 + signForm() 함수 추가됨.

executeForm 함수 추가
*/

#include <string>

class AForm;
class Bureaucrat {
 private:
  const std::string name_;
  int grade_;
 public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &copy);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &src);

  const std::string &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &form);
  void executeForm(AForm const &form);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif