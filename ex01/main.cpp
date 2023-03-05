#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << "==============Bureaucrat Constructor Check==============" << std::endl;
    Bureaucrat jeongkpa("jeongkpa", 1);
    Bureaucrat polar("polar", 50);
    Bureaucrat dalle("dalle", 130);

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
    jeongkpa.signForm(form1);
    std::cout << form1 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << "==============Form Exception Check==============" << std::endl;
    polar.signForm(form3); // GradeTooLowException
    dalle.signForm(form1); // SignedAlreadyException
    dalle.signForm(form2);
    polar.signForm(form4);

    std::cout << "==============Destructor Check==============" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}