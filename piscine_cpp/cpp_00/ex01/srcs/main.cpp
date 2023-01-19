#include "../includes/Phonebook.hpp"
#include "../includes/Contact.hpp"

void    print_info(std::string str)
{
    unsigned int i(10);

    std::cout << '|';
    while (i > str.size())
    {
        std::cout << ' ';
        i--;
    }
    i = 0;
    while (str[i] && i < 9)
    {
        std::cout << str[i];
        i++;
    }
    if (str[i] && str[i + 1])
        std::cout << '.';
    else
        std::cout << str[i];
}

int main ()
{
	std::string cmd;
	bool exit(false);
	Phonebook pb;

	std::cout << "-->        PHONEBOOK PROGRAM !! :D         <--" << std::endl;
	std::cout << "--> Available commands : ADD, SEARCH, EXIT <--" << std::endl;
	std::cout << "-->        You may enter a command...      <--" << std::endl;
	std::cout << std::endl;

	while (exit == 0)
	{
		std::cout << "@User input >";//pas sûr du std::endl ici
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.add_contact();
		else if (cmd == "SEARCH")
			pb.search_contact();
		else if (cmd == "EXIT")
			exit = true;
		else
		{
			std::cout << "The expected commands are only literally 'ADD' 'SEARCH' or 'EXIT'... Please try again" << std::endl;
		}
		//++ de gestion d'erreur ??? cf M;
		cmd.erase();
	}
	std::cout << std::endl;
	std::cout << "Ciao ! ;-)" << std::endl;
	return (0);
}