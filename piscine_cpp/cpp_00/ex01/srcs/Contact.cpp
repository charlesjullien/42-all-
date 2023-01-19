#include "../includes/Phonebook.hpp"
#include "../includes/Contact.hpp"

std::string Contact::first_name() { return m_first_name; }
std::string Contact::last_name() { return m_last_name; }
std::string Contact::nickname() { return m_nickname; }
std::string Contact::phone_number() { return m_phone_number; }
std::string Contact::secret() { return m_secret; }

void    Contact::add_new(std::string *data, std::string str)
{
	std::cout << "Enter " << str << " : " << std::endl;
	std::getline(std::cin, *data);
}

void    Contact::ask_data()
{
	add_new(&m_first_name, "first name");
	add_new(&m_last_name, "last name");
	add_new(&m_nickname, "nickname");
	add_new(&m_phone_number, "phone number");
	add_new(&m_secret, "darkest secret");
}

void Contact::print_contact()
{
	print_info(m_first_name);
	print_info(m_last_name);
	print_info(m_nickname);
	std::cout << "|" << std::endl;
}