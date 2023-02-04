#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string f_name;
		std::string l_name;
		std::string alias;
		std::string phone;
		std::string secret;

	public:
		void set_field(int f_type, std::string* in, const std::string& phrase);
		std::string get_f_name(void) const;
		std::string get_l_name(void) const;
		std::string get_alias(void) const;
		std::string get_phone(void) const;
		std::string get_secret(void) const;
		Contact(void);
		~Contact(void);
};


class PhoneBook
{
	private:
		const std::string cmd_exit;
		const std::string cmd_add;
		const std::string cmd_search;
		std::string cmd;
		Contact c[PB_SIZE];
		int i;
		bool o;

		void panel_header(void);
		std::string cut(std::string s);
		void detail(void);

	public:
		void panel_cmd(void);
		void cmd_input(void);
		int cmd_type(void);
		std::string cmd_output(void);
		void contact_add(void);
		void contact_search(void);

		PhoneBook(void);
		~PhoneBook(void);
};
#endif