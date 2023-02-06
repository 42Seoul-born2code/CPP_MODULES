#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;

	public:
		Contact();
		Contact(const std::string &first_name,
				const std::string &last_name,
				const std::string &nick_name,
				const std::string &phone_number,
				const std::string &darkest_secret);
		~Contact();
		const std::string &get_first_name();
		const std::string &get_last_name();
		const std::string &get_nick_name();
		const std::string &get_phone_number();
		const std::string &get_darkest_secret();
};

#endif