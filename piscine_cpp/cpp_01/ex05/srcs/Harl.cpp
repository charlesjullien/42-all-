#include "../includes/Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl Created..." << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketcup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ft_Harl)(void);
	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	int index;
	while (tab[i] != level)
		i++;
	index = i;
	switch (index)
	{
		case 0:
		{
			ft_Harl = &Harl::debug;
			(this->*ft_Harl)();
			break;
		}
		case 1:
		{
			ft_Harl = &Harl::info;
			(this->*ft_Harl)();
			break;
		}
		case 2:
		{
			ft_Harl = &Harl::warning;
			(this->*ft_Harl)();
			break;
		}
		case 3:
		{
			ft_Harl = &Harl::error;
			(this->*ft_Harl)();
			break;
		}
	
		default:
		{
			std::cout << "Harl needs an update..." << std::endl;
			break;
		}
	}
}

Harl::~Harl()
{
	std::cout << "Harl Black-Holed..." << std::endl;
}