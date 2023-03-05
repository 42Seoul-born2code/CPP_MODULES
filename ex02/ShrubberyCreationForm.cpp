#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

// Constructor & Destructor
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "Default Constructor of ShrubberyCreationForm called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137) {
  this->target_ = target;
  std::cout << "Constructor of ShrubberyCreationForm(target) called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form("ShrubberyCreationForm",
                                                                                       145,
                                                                                       137) {
  this->target_ = copy.target_;
  std::cout << "Copy Constructor of ShrubberyCreationForm called" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
}

// Operator Overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  this->target_ = src.target_;
  return (*this);
}

// Method
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  AForm::execute(executor);
  std::ofstream file(target_ + "_shrubbery");
  file << "          &&& &&  & &&\n"
          "      && &\\/&\\|& ()|/ @, &&\n"
          "      &\\/(/&/&||/& /_/)_&/_&\n"
          "   &() &\\/&|()|/&\\/ '%\" & ()\n"
          "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
          "&&   && & &| &| /& & % ()& /&&\n"
          " ()&_---()&\\&\\|&&-&&--%---()~\n"
          "     &&     \\|||\n"
          "             |||\n"
          "             |||\n"
          "             |||\n"
          "       , -=-~  .-^- _";
  file.close();
}