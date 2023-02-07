#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

/*
생성자와 소멸자
index : contact를 저장한 index
count : contact에 연락처를 저장할 때 마다 +1
*/
PhoneBook::PhoneBook() 
{
  index = 0;
  count = 0;
}
PhoneBook::~PhoneBook() {}

/*
EOF 입력 예외처리를 위한 함수
*/

void PhoneBook::check_eof()
{
  if (std::cin.eof())
  {
    std::cout << "EOF FOUND!! EXIT" << std::endl;
    exit(1);
  }
}

/*
getline으로 받은 search_str을 int값으로 변경하여 반환
문자열 중에 숫자가 아닌 다른 문자가 포함돼있다면 -1 반환
overflow인데, 인덱스가 음수일 수는 없으므로 양수로 변환하여 반환
*/

static int string_to_int(std::string search_str)
{
  int temp;

  temp = 0;
  for (unsigned long i = 0; i <= search_str.size() - 1; i++)
  {
    if (search_str[i] < '0' || search_str[i] > '9')
      return (-1);
    else
      temp = temp * 10 + search_str[i] - '0';
  }
  if (temp < 0)
    temp = -temp;
  return (temp);
}

/*
str의 길이를 측정하여, 10보다 크다면 substr함수를 통해서 9까지 출력 후 . 추가하여 반환
*/
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

/*
getline함수로 contact에 들어갈 친구들을 입력 받는다.

입력을 받았는데, 첫글자가 널이라면 invalid value found
정상적인 입력이라면, Contact 객체 생성 (생성자 호출)
index값과 count값을 1씩 증가하는데, 만약 index+1 = 8 (9번째 연락처 저장인 경우) 일 때 index를 0으로 초기화 해준다.
*/
int PhoneBook::add_contact()
{
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  std::cout << "first_name : ";
  std::getline(std::cin, first_name);
  check_eof();
  std::cout << "last_name : ";
  std::getline(std::cin, last_name);
  check_eof();
  std::cout << "nick_name : ";
  std::getline(std::cin, nick_name);
  check_eof();
  std::cout << "phone_number : ";
  std::getline(std::cin, phone_number);
  check_eof();
  std::cout << "darkest_secret : ";
  std::getline(std::cin, darkest_secret);
  check_eof();

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

/*
std::setw(n)은 오른쪽으로 정렬하여 n의 크기만큼 출력 (n = 10)
empty() 함수는 문자열이 비어있는지 확인하는 함수.
index가 음수이거나, index가 8이상인경우, contacts_[index]의 get_first_name한 문자열이 만약 비어있다면 Invalid 예외처리

*/
void PhoneBook::get_contact(int index)
{
  if (index < 0 || index >= MAX_CONTACT_NUM || contacts_[index].get_first_name().empty())
  {
    std::cout << "Error: Invalid index number." << std::endl;
    return ;
  }
  std::cout << "first_name : " << contacts_[index].get_first_name() << std::endl
            << "last_name : " << contacts_[index].get_last_name() << std::endl
            << "nick_name : " << contacts_[index].get_nick_name() << std::endl
            << "phone_number : " << contacts_[index].get_phone_number() << std::endl
            << "darkest_secret : " << contacts_[index].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{
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

  std::string search_str;
  int search_num;
  while(1)
  {
    std::cout << "WHAT INDEX DO YOU WANT TO SEARCH: ";
		std::getline(std::cin, search_str);
    if (std::cin.eof())
    check_eof();
    search_num = string_to_int(search_str);
    if (search_num == -1)
    {
			std::cout << "Wrong INPUT, Try Again" << std::endl;
			continue;
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