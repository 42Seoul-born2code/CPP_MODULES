#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}
Contact::Contact(	const std::string &first_name,
					const std::string &last_name,
					const std::string &nick_name,
					const std::string &phone_number,
					const std::string &darkest_secret
				)
				{
					first_name_ = first_name;
					last_name_ = last_name;
					nick_name_ = nick_name;
					phone_number_ = phone_number;
					darkest_secret_ = darkest_secret;
				}

Contact::~Contact() {}

const std::string &Contact::get_first_name() const { return first_name_;}
const std::string &Contact::get_last_name() const { return last_name_;}
const std::string &Contact::get_nick_name() const { return nick_name_;}
const std::string &Contact::get_phone_number() const { return phone_number_;}
const std::string &Contact::get_darkest_secret() const { return darkest_secret_;}