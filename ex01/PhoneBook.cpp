#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {index = 0;}
PhoneBook::~PhoneBook() {}

static std::string print_max_string(std::string str)
{
  if (str.length() > MAX_COL_WIDTH)
  {
    std::string sub_str = str.substr(0, 9) + ".";
    return sub_str;
  }
  else
    return str;
}

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

int PhoneBook::get_contact(int index)
{
  if (index >= MAX_CONTACT_NUM || contacts_[index].get_first_name().empty())
  {
    std::cout << "Error: Invalid index number." << std::endl;
    return (-1);
  }
  std::cout << std::setw(10) << "first_name : " << contacts_[index].get_first_name() << std::endl
            << std::setw(10) << "last_name : " << contacts_[index].get_last_name() << std::endl
            << std::setw(10) << "nick_name : " << contacts_[index].get_nick_name() << std::endl
            << std::setw(10) << "phone_number : " << contacts_[index].get_phone_number() << std::endl
            << std::setw(10) << "darkest_secret : " << contacts_[index].get_darkest_secret() << std::endl;
  return (0);
}

int PhoneBook::search_contact()
{
  std::string str;
  int index;

  std::cout << std::setw(10) << "index" << "|"
            << std::setw(10) << "first_name" << "|"
            << std::setw(10) << "last_name" << "|"
            << std::setw(10) << "nick_name" << std::endl;
  for (int i = 0; i < MAX_CONTACT_NUM && !contacts_[i].get_first_name().empty(); i++)
  {
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << print_max_string(contacts_[i].get_first_name()) << "|"
              << std::setw(10) << print_max_string(contacts_[i].get_last_name()) << "|"
              << std::setw(10) << print_max_string(contacts_[i].get_nick_name()) << std::endl;
  }
  std::cout << "WHAT INDEX DO YOU WANT TO SEARCH: ";
  std::getline(std::cin, str);
  //TODO: str이 0~7 값이 아닌경우 에러처리
  index = std::atoi(str.c_str());

  return (get_contact(index));
}