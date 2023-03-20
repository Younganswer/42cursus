#include "../incs/BitcoinExchange.hpp"
#include <iostream>
#include <sstream>

std::vector<Data>	BitcoinExchange::_db;

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
	std::ifstream	ifs;
	std::string		line;
	Data			data;

	BitcoinExchange::openFile(ifs, filename);
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		data = Data(line);
		if (1000 < data.getValue()) {
			throw (BitcoinExchange::TooLargeValueError(data.getValue()));
		}
		std::vector<Data>::iterator	iter = std::upper_bound(BitcoinExchange::_db.begin(), BitcoinExchange::_db.end(), data);
		if (iter == BitcoinExchange::_db.begin()) {
			std::cout << "No match" << '\n';
		} else {
			iter--;
			if (iter == BitcoinExchange::_db.begin()) {
				std::cout << "No match" << '\n';
			} else {
				std::cout << *iter << '\n';
			}
		}
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

// Exception: TooLargeValueError
BitcoinExchange::TooLargeValueError::TooLargeValueError(void): _msg("Too large value") {}
BitcoinExchange::TooLargeValueError::TooLargeValueError(float value) {
	this->_msg = std::string("Too large value: ") + std::to_string(value);
}
BitcoinExchange::TooLargeValueError::~TooLargeValueError(void) throw() {}
const char *BitcoinExchange::TooLargeValueError::what(void) const throw() {
	return (this->_msg.c_str());
}
