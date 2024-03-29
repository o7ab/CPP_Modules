#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 1
// 2012-01-11 | 2147483648

class BitcoinExchange
{
	private:
		std::map<std::string, double> exchangeRates;
		std::string exchangeName;
		std::string newDate;
		double newRate;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string exchangeName);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		// void setExchangeRate(std::string currency, double rate);
		// double getExchangeRate(std::string currency);
		// std::string getExchangeName();
		void	printExchangeRates(std::string file);
		void	parseLine(std::string currency, std::string rate);

		// utils
		bool		isValidDate(std::string date);
		bool		isValidNumber(std::string rate);
		std::string	getnewDate(std::string date);
};

#endif