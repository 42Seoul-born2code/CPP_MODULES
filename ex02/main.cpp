#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Bureaucrat Constructor Check==============" << std::endl;
    Bureaucrat kevin("Kevin", 1);
    Bureaucrat alex("Alex", 50);
    Bureaucrat jenny("Jenny", 130);

    std::cout << "==============Concrete Form Constructor Check==============" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm roboto("office");
    PresidentialPardonForm presidential("harry");

    std::cout << shrubbery << std::endl;
    std::cout << roboto << std::endl;
    std::cout << presidential << std::endl;

    std::cout << "==============ShrubberyCreationForm Check==============" << std::endl;
    jenny.executeForm(shrubbery); // NotSignedException
    jenny.signForm(shrubbery);
    jenny.executeForm(shrubbery);

    std::cout << "==============RobotomyRequestForm Check==============" << std::endl;
    alex.signForm(roboto);
    alex.executeForm(roboto); // GradeTooLowException
    kevin.executeForm(roboto);

    std::cout << "==============PresidentialPardonForm Check==============" << std::endl;
    kevin.signForm(presidential);
    jenny.executeForm(presidential); // GradeTooLowException
    alex.executeForm(presidential); // GradeTooLowException
    kevin.executeForm(presidential);

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}