#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Constructor Check==============" << std::endl;
    Bureaucrat a;
    Bureaucrat b("jeongkpa", 1);
    Bureaucrat c(b);
    Bureaucrat d;
    d = a;

    std::cout << "==============Check Instance a, b, c, d==============" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "==============Check Increment, Decrement Method==============" << std::endl;
    a.incrementGrade();
    b.decrementGrade();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "==============Check Getter Method==============" << std::endl;
    std::cout << a.getName() << " : " << a.getGrade() << std::endl;
    std::cout << b.getName() << " : " << b.getGrade() << std::endl;
    std::cout << c.getName() << " : " << c.getGrade() << std::endl;
    std::cout << d.getName() << " : " << d.getGrade() << std::endl;

    std::cout << "==============Exception Check==============" << std::endl;
    c.incrementGrade(); // GradeTooHighException
    d.decrementGrade(); // GradeTooLowException
    Bureaucrat error1("error1", 0); // GradeTooHighException
    Bureaucrat error2("error2", 151); // GradeTooLowException

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}