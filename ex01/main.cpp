#include "./PhoneBook.hpp"

void check_leaks()
{
	system("leaks PhoneBook | grep leaks");
}

int main(void)
{
	atexit(check_leaks);
	PhoneBook pb;
	std::string command;
	while (1)
	{
		std::cout << "Please write command without whitespace \"ADD\" or \"SEARCH\" or \"EXIT\" : ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "EOF FOUND!! EXIT" << std::endl;
			exit(1);
		}
		else if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH")
			pb.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "Bye. Have a good time :)" << std::endl;
			break;
		}
		else
		{
			std::cout << "Error: Wrong Command." << std::endl;
			command =  "\0";
		}
	}
	return 0;
}