#include "./PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string command;
	while (1)
	{
		std::cout << "SELECT COMMAND || ADD | SEARCH | EXIT || : ";
		std::getline(std::cin, command);

		if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH") // TODO: SEARCH 실패 시 리턴 값 없도록
			pb.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "Bye. Have a good time :)" << std::endl;
			break;
		}
		else
			std::cout << "Error: Wrong Command." << std::endl;
	}	
	return 0;
}