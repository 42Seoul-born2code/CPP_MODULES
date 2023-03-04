#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Bureaucrat Constructor Check==============" << std::endl;
    Bureaucrat kevin("Kevin", 1);
    Bureaucrat alex("Alex", 50);
    Bureaucrat jenny("Jenny", 130);

    std::cout << "==============Form Constructor Check==============" << std::endl;
    Form form1("importantForm", 2, 1);
    Form form2;
    Form form3(form1);
    Form form4;
    form4 = form2;

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;
    std::cout << form4 << std::endl;

    std::cout << "==============Form Method Check==============" << std::endl;
    std::cout << form1 << std::endl;
    kevin.signForm(form1);
    std::cout << form1 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << "==============Form Exception Check==============" << std::endl;
    alex.signForm(form3); // GradeTooLowException
    jenny.signForm(form1); // SignedAlreadyException
    jenny.signForm(form2);
    alex.signForm(form4);

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}