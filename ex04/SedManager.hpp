#ifndef SEDMANAGER_HPP
#define SEDMANAGER_HPP

#include <string>
#include <fstream>
#include <iostream>

class SedManager
{
	private:
		std::ifstream infile_;
		std::ofstream outfile_;
		std::string buf_;
	public:
		SedManager();
		~SedManager();
		int check_valid_file(std::string infile, std::string outfile);
		int replace_str(std::string pattern, std::string replacement);
		void close_file();
};

#endif