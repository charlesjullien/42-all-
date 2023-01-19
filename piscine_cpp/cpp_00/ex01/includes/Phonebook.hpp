#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class Phonebook
{
	public :

	Phonebook();
	void add_contact(void);
	void search_contact(void);
	void print_contact(void);
	void get_contact(int index);
	bool phonebook_full(void);
	void new_contact(Contact *n);

	~Phonebook();

	private :

	int m_sum_contact;
	Contact contact[8];
	int _oldest;
};

void print_info(std::string str);

#endif