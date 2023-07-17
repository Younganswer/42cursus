#include "../incs/BitcoinExchange.hpp"
#include "../incs/DataBase.hpp"
#include "../incs/istringstream.hpp"
#include <iostream>
#include <sstream>

Header	BitcoinExchange::_header;

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { (void) ref; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) { (void) rhs; return (*this); }

bool	BitcoinExchange::exchange(const std::string &filename) throw(std::exception) {
	std::ifstream	ifs(filename);
	std::string		line;

	if (!ifs.is_open()) {
		throw (FailToOpenFileException());
	}
	try {
		BitcoinExchange::_parseHeader(ifs);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToParseHeaderException());
	}
	while (std::getline(ifs, line)) {
		try {
			BitcoinExchange::_exchange(line);
		} catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return (true);
}

bool	BitcoinExchange::_parseHeader(std::ifstream &ifs) throw(std::exception) {
	std::string	line;

	if (!std::getline(ifs, line)) {
		throw (InvalidSyntaxException());
	}
	try {
		BitcoinExchange::_header = Header(line);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToConstructHeaderException());
	}
	return (true);
}

bool	BitcoinExchange::_exchange(const std::string &line) throw(std::exception) {
	ft::istringstream	iss(line);
	std::string			token, date_token, value_token;

	for (size_t i=0; i<BitcoinExchange::_header.size(); ++i) {
		iss >> token;
		if (BitcoinExchange::_header[i] == "date") {
			date_token = token;
		} else if (BitcoinExchange::_header[i] == "value") {
			value_token = token;
		} else {
			throw (InvalidSyntaxException());
		}
		if (BitcoinExchange::_isInvalidValue(value_token)) {
			throw (InvalidArgumentException());
		}
	}
	if (date_token.empty() || value_token.empty()) {
		throw (InvalidSyntaxException());
	}
	try {
		Date						date = Date(date_token);
		DataBase::const_iterator	it = DataBase::getInstance().lower_bound(date);
		ExchangeRate				exchange_rate;
		double						value;

		if (it == DataBase::getInstance().begin()) {
			throw (FailToExchangeException());
		}
		exchange_rate = (--it)->second;
		value = std::atof(value_token.c_str());
		if (value < 0) {
			throw (NotAPositiveNumberException());
		} else if (value == 0) {
			throw (InvalidArgumentException());
		} else if (1000 < value) {
			throw (TooLargeNumberException());
		}
		std::cout << date << " => " << value << " = " << value * exchange_rate.getRate() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (true);
}

bool	BitcoinExchange::_isInvalidValue(const std::string &value) {
	bool	dot = false;

	for (size_t i=0; i<value.size(); ++i) {
		if (value[i] == '.') {
			if (dot) {
				return (true);
			}
			dot = true;
		} else if (!std::isdigit(value[i])) {
			return (true);
		}
	}
	return (false);
}

const char	*BitcoinExchange::FailToOpenFileException::what(void) const throw() { return ("BitcoinExchange: Fail to open file"); }
const char	*BitcoinExchange::FailToParseHeaderException::what(void) const throw() { return ("BitcoinExchange: Fail to parse"); }
const char	*BitcoinExchange::FailToConstructHeaderException::what(void) const throw() { return ("BitcoinExchange: Fail to construct header"); }
const char	*BitcoinExchange::InvalidSyntaxException::what(void) const throw() { return ("BitcoinExchange: Invalid syntax"); }
const char	*BitcoinExchange::FailToExchangeException::what(void) const throw() { return ("BitcoinExchange: Fail to exchange"); }
const char	*BitcoinExchange::InvalidArgumentException::what(void) const throw() { return ("BitcoinExchange: Invalid argument"); }
const char	*BitcoinExchange::NotAPositiveNumberException::what(void) const throw() { return ("BitcoinExchange: Not a positive number"); }
const char	*BitcoinExchange::TooLargeNumberException::what(void) const throw() { return ("BitcoinExchange: Too large number"); }