#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {index = 0;}
PhoneBook::~PhoneBook() {}

// static std::string print_max_string(std::string str)
// {
//   if (str.length() > MAX_COL_WIDTH)
//   {
//     std::string sub_str = str.substr(0, 9) + ".";
//     return sub_str;
//   }
//   else
//     return str;
// }

int PhoneBook::add_contact()
{
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  std::cout << "first_name : ";
  std::getline(std::cin, first_name);
  std::cout << "last_name : ";
  std::getline(std::cin, last_name);
  std::cout << "nick_name : ";
  std::getline(std::cin, nick_name);
  std::cout << "phone_number : ";
  std::getline(std::cin, phone_number);
  std::cout << "darkest_secret : ";
  std::getline(std::cin, darkest_secret);

  if (!first_name[0] || !last_name[0] || !nick_name[0] || !phone_number[0] || !darkest_secret[0])
  {
    std::cout << "Error: Invalid value found... Please try valid data" << std::endl;
    return (-1);
  }
  Contact newContact(first_name, last_name, nick_name, phone_number, darkest_secret);
  contacts_[index] = newContact;
  if (index + 1 == MAX_CONTACT_NUM)
    index = 0;
  else
    index +=1;
  return index;
}