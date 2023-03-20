#include "../incs/BitcoinExchange.hpp"
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void) rhs;
	return (*this);
}

bool	BitcoinExchange::initializeDB(void) throw(std::exception) {
	std::ifstream	ifs;
	std::string		line;

	BitcoinExchange::openFile(ifs, "data.csv");
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		BitcoinExchange::_db.push_back(Data(line, ','));
	}
	return (true);
}

bool	BitcoinExchange::openFile(std::ifstream &ifs, const std::string &filename) {
	ifs.open(filename);
	if (!ifs.is_open()) {
		throw (BitcoinExchange::FileOpenError(filename));
	}
	return (true);
}

bool	BitcoinExchange::showDB(void) {
	for (std::vector<Data>::iterator it=BitcoinExchange::_db.begin(); it!=BitcoinExchange::_db.end(); it++) {
		std::cout << *it << '\n';
	}
	return (true);
}

bool	BitcoinExchange::exchange(const std::string &filename) {
	std::ifstream		ifs;

	BitcoinExchange::openFile(ifs, filename);
	return (true);
}

// Exception: FileOpenError
BitcoinExchange::FileOpenError::FileOpenError(void): _msg("Fail to open file") {}
BitcoinExchange::FileOpenError::FileOpenError(const std::string &filename): _msg(std::string("Fail to open file: ") + filename) {}
BitcoinExchange::FileOpenError::~FileOpenError(void) throw() {}
const char *BitcoinExchange::FileOpenError::what(void) const throw() {
	return (this->_msg.c_str());
}