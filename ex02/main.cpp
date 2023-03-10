#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Bureaucrat Constructor Check==============" << std::endl;
    Bureaucrat jeongkpa("jeongkpa", 1);
    Bureaucrat wonkim("wonkim", 50);
    Bureaucrat joonhan("joonhan", 130);

    std::cout << "==============Concrete Form Constructor Check==============" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm roboto("office");
    PresidentialPardonForm presidential("harry");

    std::cout << shrubbery << std::endl;
    std::cout << roboto << std::endl;
    std::cout << presidential << std::endl;

    std::cout << "==============ShrubberyCreationForm Check==============" << std::endl;
    joonhan.executeForm(shrubbery); // NotSignedException
    joonhan.signForm(shrubbery);
    joonhan.executeForm(shrubbery);

    std::cout << "==============RobotomyRequestForm Check==============" << std::endl;
    wonkim.signForm(roboto);
    wonkim.executeForm(roboto); // GradeTooLowException
    jeongkpa.executeForm(roboto);

    std::cout << "==============PresidentialPardonForm Check==============" << std::endl;
    jeongkpa.signForm(presidential);
    joonhan.executeForm(presidential); // GradeTooLowException
    wonkim.executeForm(presidential); // GradeTooLowException
    jeongkpa.executeForm(presidential);

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}