#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include "Contact.hpp"

#define MAX_CONTACT_NUM 8
#define MAX_COL_WIDTH 10

class PhoneBook
{
	private:
		Contact contacts_[MAX_CONTACT_NUM];
		int index;
		int count;
	public:
		PhoneBook();
		~PhoneBook();
		int 	add_contact(void);
		void	search_contact(void);
		void 	get_contact(int index);
};
#endif