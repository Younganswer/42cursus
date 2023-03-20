#include "../incs/BitcoinExchange.hpp"
#include <iostream>
#include <sstream>

_Info::_Info(const std::string &date, float value): date(date), value(value) {}

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void) rhs;
	return (*this);
}

bool	BitcoinExchange::openFile(std::ifstream &ifs, const std::string &filename) {
	ifs.open(filename);
	if (!ifs.is_open()) {
		throw BitcoinExchange::FileOpenError(filename);
	}
	return (true);
}

bool	BitcoinExchange::initializeQueue(std::queue<Info> &info_q, std::ifstream &ifs) throw(std::exception) {
	std::string	line;
	std::string	date;
	std::string	delimeter;
	float		value;

	std::getline(ifs, line);
	while (std::getline(ifs, line)) {
		std::istringstream	iss(line);

		iss >> date;
		if (invalidDate(date)) {
			throw (BitcoinExchange::InvalidDateError(date));
		}

		iss >> delimeter;
		if (delimeter != "|") {
			throw (BitcoinExchange::InvalidFormatError(delimeter));
		}

		iss >> value;
		if (value < 0) {
			throw (BitcoinExchange::NegativeNumberError(value));
		} else if (1000 < value) {
			throw (BitcoinExchange::TooLargeNumberError(value));
		}

		info_q.push(_Info(date, value));
	}
	return (true);
}

bool	BitcoinExchange::invalidDate(const std::string &date) {
	const int	dateInMonth[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	if (date.size() != 10) {
		return (true);
	}
	if (date[4] != '-' || date[7] != '-') {
		return (true);
	}
	for (int i=0; i<10; i++) {
		if (i == 4 || i == 7) {
			continue ;
		}
		if (date[i] < '0' || '9' < date[i]) {
			return (true);
		}
	}

	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if (month < 1 || 12 < month) {
		return (true);
	}
	if (day < 1 || dateInMonth[month - 1] < day) {
		return (true);
	}
	if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::exchange(const std::string &filename) {
	std::ifstream		ifs;
	std::queue<Info>	info_q;

	BitcoinExchange::openFile(ifs, filename);
	BitcoinExchange::initializeQueue(info_q, ifs);
	while (info_q.empty() == false) {
		std::cout << info_q.front().date << " | " << info_q.front().value << '\n';
		info_q.pop();
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

// Exception: InvalidDateError
BitcoinExchange::InvalidDateError::InvalidDateError(void): _msg("Invalid date") {}
BitcoinExchange::InvalidDateError::InvalidDateError(const std::string &date): _msg(std::string("Invalid date: ") + date) {}
BitcoinExchange::InvalidDateError::~InvalidDateError(void) throw() {}
const char *BitcoinExchange::InvalidDateError::what(void) const throw() {
	return (this->_msg.c_str());
}

// Exception: InvalidFormatError
BitcoinExchange::InvalidFormatError::InvalidFormatError(void): _msg("Invalid format") {}
BitcoinExchange::InvalidFormatError::InvalidFormatError(const std::string &distributor): _msg(std::string("Invalid format: ") + distributor) {}
BitcoinExchange::InvalidFormatError::~InvalidFormatError(void) throw() {}
const char *BitcoinExchange::InvalidFormatError::what(void) const throw() {
	return (this->_msg.c_str());
}

// Exception: NegativeNumber
BitcoinExchange::NegativeNumberError::NegativeNumberError(void): _msg("Negative number") {}
BitcoinExchange::NegativeNumberError::NegativeNumberError(float number): _msg(std::string("Negative number: ") + std::to_string(number)) {}
BitcoinExchange::NegativeNumberError::~NegativeNumberError(void) throw() {}
const char *BitcoinExchange::NegativeNumberError::what(void) const throw() {
	return (this->_msg.c_str());
}

// Exception: TooLargeNumber
BitcoinExchange::TooLargeNumberError::TooLargeNumberError(void): _msg("Too large number") {}
BitcoinExchange::TooLargeNumberError::TooLargeNumberError(float number): _msg(std::string("Too large number: ") + std::to_string(number)) {}
BitcoinExchange::TooLargeNumberError::~TooLargeNumberError(void) throw() {}
const char *BitcoinExchange::TooLargeNumberError::what(void) const throw() {
	return (this->_msg.c_str());
}