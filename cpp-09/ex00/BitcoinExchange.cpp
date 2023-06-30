#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	newDate = "";
	newRate = 0;
	this->exchangeName = "default";
}

BitcoinExchange::~BitcoinExchange()
{
	this->exchangeRates.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->exchangeName = other.exchangeName;
		this->exchangeRates = other.exchangeRates;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(std::string exchangeName)
{
	this->exchangeName = exchangeName;
	std::ifstream input("data.csv");
	if(!input.is_open())
	{
		std::cout << RED <<  "Error: file not found." << RESET << std::endl;
		return;
	}
	std::string line;
	while(std::getline(input, line))
	{
		size_t pos = line.find(',');
		if (pos == line.npos)
		{
			std::cout << RED << "Error: invalid file format." << RESET << std::endl;
			return;
		}
		std::string date = line.substr(0, line.find(','));
		std::string rate = line.substr(line.find(',') + 1);
		this->exchangeRates[date] = std::atof(rate.c_str());
	}
	input.close();
}

std::string BitcoinExchange::getnewDate(std::string date)
{
	std::map<std::string, double>::iterator it = this->exchangeRates.lower_bound(date);
	if (it == this->exchangeRates.end())
		return exchangeRates.rbegin()->first;
	if (it->first == date)
		return date;
	if (it == this->exchangeRates.begin())
		return it->first;
	else
		it--;
	return it->first;
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	// std::cout << date.length() << std::endl;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	if (std::atoi(date.substr(0, 4).c_str()) < 2009 || std::atoi(date.substr(0, 4).c_str()) > 2021)
		return false;
	if (std::atoi(date.substr(5, 2).c_str()) < 1 || std::atoi(date.substr(5, 2).c_str()) > 12)
		return false;
	if (std::atoi(date.substr(8, 2).c_str()) < 1 || std::atoi(date.substr(8, 2).c_str()) > 31)
		return false;
	if (std::atoi(date.substr(5, 2).c_str()) == 2 && std::atoi(date.substr(8, 2).c_str()) > 29)
		return false;
	this->newDate = getnewDate(date);
	return true;
}

bool	BitcoinExchange::isValidNumber(std::string rate)
{
	if (rate.length() == 0)
		return false;
	if (rate.find(".") == rate.npos)
	{
		if (std::atoi(rate.c_str()) < 0 || std::atoi(rate.c_str()) > 1000)
			return false;
	}
	else
	{
		if (std::atof(rate.c_str()) < 0 || std::atof(rate.c_str()) > 1000)
			return false;
	}
	this->newRate = std::atof(rate.c_str());
	return true;
}

void	BitcoinExchange::parseLine(std::string date, std::string rate)
{
	if (date.find('-') == date.npos)
	{
		std::cout << RED << "Error: invalid file format." << RESET << std::endl;
		return;
	}
	if (isValidDate(date) == false)
	{
		std::cout << RED << "Error: invalid date." << RESET << std::endl;
		return;
	}
	if (isValidNumber(rate) == false)
	{
		std::cout << RED << "Error: invalid value" << RESET << std::endl;
		return;
	}
	std::cout << date << " => " << this->newRate << " = " << this->newRate * this->exchangeRates[this->newDate] << std::endl;
}


void	BitcoinExchange::printExchangeRates(std::string file)
{
	std::ifstream input(file.c_str());
	if(!input.is_open())
	{
		std::cout << RED << "Error: file not found." << RESET << std::endl;
		return;
	}
	std::string line;
	while(std::getline(input, line))
	{
		size_t pos = line.find('|');
		if (pos == line.npos)
		{
			std::cout << RED << "Error: invalid file format." << RESET << std::endl;
			continue;
		}
		std::string date = line.substr(0, line.find(' '));
		std::string rate = line.substr(line.find('|') + 1);
		this->parseLine(date, rate);
	}
}