#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include "Account.hpp"

Account::Account(void)
{
	return ;
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += Account::checkAmount();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "created" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << Account::checkAmount() << ";" << "withdrawal:";
	if (Account::checkAmount() > withdrawal){
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << (this->_amount -= withdrawal) << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		return true;
	}
	std::cout << "refused" << std::endl;
	return false;
}


void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << (this->_amount += deposit) << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}


int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}


int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts); 
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	 time_t now = std::time(0); 
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << 1 +ltm->tm_mon << ltm->tm_mday << "_";
    if (ltm->tm_hour < 10)
        std::cout << 0;
    std::cout <<  ltm->tm_hour << ltm->tm_min; 
    if (ltm->tm_min < 10)
        std::cout << 0;
    std::cout << ltm->tm_min;
    if (ltm->tm_sec < 10)
        std::cout << 0;
    std::cout << ltm->tm_sec << "] "; 
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "closed" << std::endl;
	Account::_totalAmount -= Account::checkAmount();
	Account::_nbAccounts -= 1;
	return ;
}
