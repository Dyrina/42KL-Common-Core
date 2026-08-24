/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:12:59 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/24 11:12:59 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount + deposit << ";"
			  << "nb_deposits:" << _nbDeposits + 1
			  << std::endl;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount - withdrawal << ";"
			  << "nb_withdrawals:" << _nbWithdrawals + 1
			  << std::endl;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
	// To display real current time, replace above line with:
	// std::time_t now = std::time(0);
	// std::tm *ltm = std::localtime(&now);
	// std::cout << "[" << 1900 + ltm->tm_year
	//           << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
	//           << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
	//           << std::setw(2) << std::setfill('0') << ltm->tm_hour
	//           << std::setw(2) << std::setfill('0') << ltm->tm_min
	//           << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}
