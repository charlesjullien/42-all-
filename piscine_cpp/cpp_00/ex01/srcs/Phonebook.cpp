#include "../includes/Phonebook.hpp"
#include "../includes/Contact.hpp"

Phonebook::Phonebook()
{
	 m_sum_contact = 0;
	 _oldest = 0;
}

bool Phonebook::phonebook_full(void)
{
	if (m_sum_contact == 8)
		return (true);
	return (false);
}

void Phonebook::print_contact(void)
{
	for (int i(1); i <= m_sum_contact; i++)
	{
		std::cout << '|';
		for(int j(0); j < 9; j++)
			std::cout << " ";
		std::cout << i;
		contact[i - 1].print_contact();
	}
}

void Phonebook::get_contact(int index)
{
	if (index < 1 || index > m_sum_contact)
	{
		std::cout << "Error : Cannot find the contact... not registred yet." << std::endl;
		return ;
	}
	std::cout << "contact index : " << index << " : " << std::endl;
	index--;
	std::cout << "first name : " << contact[index].first_name() << std::endl;
	std::cout << "last name : " << contact[index].last_name() << std::endl;
	std::cout << "nickname :" << contact[index].nickname() << std::endl;
	std::cout << "phone number : " << contact[index].phone_number() << std::endl;
	std::cout << "darkest secret : " << contact[index].secret() << std::endl;
}

void Phonebook::new_contact(Contact *n)
{
	if (!phonebook_full())
	{
		contact[m_sum_contact] = *n;
		m_sum_contact++;
	}
	else
	{
		contact[_oldest] = *n;
		_oldest++;
		if (_oldest == 8)
			_oldest = 0;
	}
}

void Phonebook::search_contact(void)
{
	std::string searched;
	int i(0);

	print_contact();
	std::cout << "Enter the contact number to get more information : ";
	std::getline(std::cin, searched);
	i = std::atoi(searched.c_str());
	if (i < 1 || i > 8)
		std::cout << "The index is beyond range (must be from from 1 to 8 included)." << std::endl;
	else
		get_contact(i);
}


void Phonebook::add_contact(void)
{
	Contact n;

	// if (this->phonebook_full())
	// {
	// 	std::cout << "PHONEBOOK IS FULL...Replacing oldest one by current." << std::endl;
	// 	return ;
	// }
	if (m_sum_contact == 8)
	{
		std::cout << "Phonebook is full... replacing oldest contact with new one" << std::endl;
	}
	std::cout << "Please fill the following informations to complete contact creation :" << std::endl;
	n.ask_data();
	this->new_contact(&n);
	std::cout << contact[m_sum_contact - 1].first_name() << " added." << std::endl;
}

Phonebook::~Phonebook()
{
	
}