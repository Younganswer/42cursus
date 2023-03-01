#include <iostream>
#include <time.h>
#include "../incs/Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ';';
	std::cout << "total:" << Account::_totalAmount << ';';
	std::cout << "deposits:" << Account::_totalNbDeposits << ';';
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << '\n';
	return;
}

Account::Account( int initial_deposit ) {
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created";
	std::cout << '\n';
	return;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed";
	std::cout << '\n';
	return;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	std::cout << "amount:" << _amount << ';';
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << '\n';
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	return;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused\n";
		return (false);
	}
	std::cout << withdrawal << ';';
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ';';
	_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << '\n';
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << '\n';
	return;
}

void	Account::_displayTimestamp( void ) {
	time_t		timer;
	struct tm	*t;

	timer = time(NULL);
	t = localtime(&timer);

	std::cout << '[';
	std::cout << t->tm_year + 1900;
	if (t->tm_mon < 9)
		std::cout << '0';
	std::cout << t->tm_mon + 1;
	if (t->tm_mday < 10)
		std::cout << '0';
	std::cout << t->tm_mday;
	std::cout << '_';
	if (t->tm_hour < 10)
		std::cout << '0';
	std::cout << t->tm_hour;
	if (t->tm_min < 10)
		std::cout << '0';
	std::cout << t->tm_min;
	if (t->tm_sec < 10)
		std::cout << '0';
	std::cout << t->tm_sec;
	std::cout << "] ";
	return;
}

Account::Account( void ) {
	_accountIndex = Account::_nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created";
	std::cout << '\n';
	return;
}