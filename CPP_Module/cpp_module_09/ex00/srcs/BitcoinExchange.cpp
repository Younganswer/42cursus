#include "../incs/BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(void): _filename("") {}
BitcoinExchange::BitcoinExchange(const std::string &filename) throw(std::exception) { this->_filename = filename; }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) throw(std::exception) {
	if (this != &rhs) {
		this->_filename = rhs._filename;
	}
	return (*this);
}

bool	BitcoinExchange::print(void) const {
	std::ifstream	file(this->_filename);
	std::string		line;

	if (!file.is_open()) {
		throw (BitcoinExchange::FileOpenError(this->_filename));
	}
	while (std::getline(file, line)) {
		std::cout << line << '\n';
	}
	return (true);
}

// Exception: FileOpenError
BitcoinExchange::FileOpenError::FileOpenError(void): _msg("Fail to open file") {}
BitcoinExchange::FileOpenError::FileOpenError(const std::string &filename): _msg(std::string("Fail to open file: ") + filename) {}
BitcoinExchange::FileOpenError::~FileOpenError(void) throw() {}

const char *BitcoinExchange::FileOpenError::what(void) const throw() {
	return (this->_msg.c_str());
}