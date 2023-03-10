#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Intern makeForm Check==============" << std::endl;
    Intern someRandomIntern;
    Bureaucrat bureaucrat("jeongkpa", 1);
    AForm *form;

    std::cout << "==============ShrubberyCreationForm Check==============" << std::endl;
    form = someRandomIntern.makeForm("ShrubberyCreationForm", "shrubbery");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);

    std::cout << "==============RobotomyRequestForm Check==============" << std::endl;
    form = someRandomIntern.makeForm("RobotomyRequestForm", "robot");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);

    std::cout << "==============PresidentialPardonForm Check==============" << std::endl;
    form = someRandomIntern.makeForm("PresidentialPardonForm", "pres");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);

    std::cout << "==============UnknownForm Check==============" << std::endl;
    form = someRandomIntern.makeForm("unknown", "unknown");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}