#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Phonebook.hpp"

class Contact
{
	public :

	void print_contact(void);//déjà dans l'autre .hpp
	void add_new(std::string *data, std::string str);
	void ask_data(void); //on demande au User les infos du new contact après "ADD"
	std::string first_name(void);
	std::string last_name(void);
	std::string nickname(void);
	std::string phone_number(void);
	std::string secret(void);

	private :

	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_number;
	std::string m_secret;
};

#endif
