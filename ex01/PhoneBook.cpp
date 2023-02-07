#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
  index = 0;
  count = 0;
  this->test = 0;
}
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
  {
    count +=1;
    index = 0;
  }
  else
  {
    count +=1;
    index +=1;
  }
  return index;
}

void PhoneBook::get_contact(int index)
{
  if (index >= MAX_CONTACT_NUM || contacts_[index].get_first_name().empty())
  {
    std::cout << "Error: Invalid index number." << std::endl;
    return ;
  }
  std::cout << std::setw(10) << "first_name : " << contacts_[index].get_first_name() << std::endl
            << std::setw(10) << "last_name : " << contacts_[index].get_last_name() << std::endl
            << std::setw(10) << "nick_name : " << contacts_[index].get_nick_name() << std::endl
            << std::setw(10) << "phone_number : " << contacts_[index].get_phone_number() << std::endl
            << std::setw(10) << "darkest_secret : " << contacts_[index].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{
  int search_num;
  // TODO: PhoneBook 비었을 때 예외처리
  if (count == 0)
  { std::cout << "Error : There is no contact" << std::endl;
    return ;
  }
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

  while(1)
  {
    std::cout << "WHAT INDEX DO YOU WANT TO SEARCH: ";
    std::cin >> search_num;
    if (std::cin.get() == EOF)
		{
			std::cout << "EOF FOUND!! EXIT" << std::endl;
			exit(1);
		}
    if (search_num > MAX_CONTACT_NUM)
    {
      std::cout << "Wrong INPUT, Try Again" << std::endl;
      continue;
    }
    index = search_num;
    break;
  }
  get_contact(index);
  return ;
}