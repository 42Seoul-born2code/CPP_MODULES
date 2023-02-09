#include "SedManager.hpp"

int main(int argc, char **argv)
{
	SedManager sed_manager;
	std::string filename;

	if (argc != 4)
	{
		std::cout << "Error: Wrong Arguments [filename] [s1] [s2]." << std::endl;
		return (1);
	}
	filename = argv[1];
	sed_manager.check_valid_file(filename, filename + ".replace");
	sed_manager.replace_str(argv[2], argv[3]);
	sed_manager.close_file();

	return (0);
}