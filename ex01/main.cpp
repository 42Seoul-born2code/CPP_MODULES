#include "phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	while (1)
	{
		switch (pb.cmd_type())
		{
			case CMD_EXIT;
				return 0;
			case CMD_ADD;
				pb.contact_add();
				break;
			case CMD_SEARCH;
				pb.contact_search();
				break;
			default;
				std::cout << "Wrong Command" << std::endl;
				continue;
		}
	}
	return 0;
}