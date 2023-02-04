#include "phonebook.hpp"

void Contact::set_field(int type, std::string* in, const std::string& out) {
  const std::string whitespace = " \t\n\v\r\f";

  in->clear();
  std::cout << out;
  if (!(std::getline(std::cin >> std::ws, *in)) || std::cin.eof())
    exit(1);
  in->erase(in->find_last_not_of(whitespace) + 1);
  switch (type) {
    case F_F_NAME:
      _f_name = *in;
      break;
    case F_L_NAME:
      _l_name = *in;
      break;
    case F_ALIAS:
      _alias = *in;
      break;
    case F_PHONE:
      _phone = *in;
      break;
    case F_SECRET:
      _secret = *in;
      break;
  }
}

std::string Contact::get_f_name(void) const {
  return f_name;
}

std::string Contact::get_l_name(void) const {
  return l_name;
}

std::string Contact::get_alias(void) const {
  return alias;
}

std::string Contact::get_phone(void) const {
  return phone;
}

std::string Contact::get_secret(void) const {
  return secret;
}

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

