#include "../incs/BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

std::vector<Data>	BitcoinExchange::_db;

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void) rhs;
	return (*this);
}

bool	BitcoinExchange::initializeDB(void) throw(std::exception) {
	std::ifstream			ifs;
	std::string				line;
	std::string::size_type	pos;

	BitcoinExchange::openFile(ifs, "./db/data.csv");
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		pos = line.find(",");
		line.erase(pos, 1);
		line.insert(pos, " | ");
		BitcoinExchange::_db.push_back(Data(line));
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
	std::ifstream				ifs;
	std::string					line;
	Data						data;
	std::vector<Data>::iterator	iter;

	BitcoinExchange::openFile(ifs, filename);
	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		try {
			data = Data(line);
		} catch (std::exception &e) {
			std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
			continue;
		} catch (...) {
			std::cerr << "\033[31m" << "Error: Unknown error" << "\033[0m" << '\n';
			continue;
		}
		if (1000 < data.getValue()) {
			std::cerr << "\033[31m" << "Error: " << "Too large value: " << data.getValue() << "\033[0m" << '\n';
			continue;
		}
		iter = std::lower_bound(BitcoinExchange::_db.begin(), BitcoinExchange::_db.end(), data);
		if (iter == BitcoinExchange::_db.begin()) {
			std::cerr << "\033[31m" << "Error: " << "No match: " << data.getValue() << "\033[0m" << '\n';
			continue;
		}
		iter--;
		std::cout << data << " = " << iter->getValue() * data.getValue() << '\n';
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