#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>

/*
C++에서 예외를 처리할 때, 예외를 발생시킨 코드에서 예외의 정보를 제공하는 것이 중요합니다. 
이 정보는 예외 클래스에서 상속받은 std::exception 클래스의 what() 함수를 통해 제공됩니다.

what() 함수는 예외 정보를 문자열 형태로 반환하는 함수입니다. virtual 키워드를 사용하는 이유는, 
이 함수가 파생 클래스에서 오버라이딩 될 수 있기 때문입니다. 예외 클래스가 std::exception을 상속받는 경우, 
예외 정보를 제공하기 위해 what() 함수를 오버라이딩하고, 문자열 형태로 예외 정보를 반환하는 것이 좋습니다.

따라서, virtual const char *what() const throw();는 std::exception 클래스에서 정의된 what() 함수를 오버라이딩하여, 
예외 정보를 문자열 형태로 반환하기 위한 함수 선언입니다. const 키워드는 반환된 문자열이 변경되지 않음을 보장하며, throw() 키워드는 이 함수가 예외를 던지지 않음을 나타냅니다.
*/

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