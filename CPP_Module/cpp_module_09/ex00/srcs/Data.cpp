#include "../incs/Data.hpp"
#include <sstream>
#include <iomanip>

Data::Data(void): _year(0), _month(0), _day(0), _value(0) {}
Data::Data(const std::string &line) throw(std::exception) {
	std::stringstream	ss(line);
	std::string			date;
	std::string			delim;
	std::string			value;

	ss >> date;
	if (this->parseDate(date) == false) {
		throw (Data::InvalidDateError(date));
	}
	ss >> delim >> value;
	try {
		this->_value = std::stof(value);
	} catch (std::exception &e) {
		throw (e);
	}
	if (this->_value < 0) {
		throw (Data::NegativeValueError(value));
	}
}
Data::Data(const std::string &line, int delim) throw(std::exception) {
	std::stringstream	ss(line);
	std::string			date;
	std::string			value;

	std::getline(ss, date, (char)delim);
	if (this->parseDate(date) == false) {
		throw (Data::InvalidDateError(date));
	}
	std::getline(ss, value, (char)delim);
	try {
		this->_value = std::stof(value);
	} catch (std::exception &e) {
		throw (e);
	}
	if (this->_value < 0) {
		throw (Data::NegativeValueError(value));
	}
}
Data::Data(const Data &ref): _year(ref._year), _month(ref._month), _day(ref._day), _value(ref._value) {}
Data::~Data(void) {}
Data	&Data::operator=(const Data &rhs) {
	this->_year = rhs._year;
	this->_month = rhs._month;
	this->_day = rhs._day;
	this->_value = rhs._value;
	return (*this);
}

bool	Data::parseDate(const std::string &date) {
	if (date.length() != 10 || std::isdigit(date[0]) == false || std::isdigit(date[1]) == false || std::isdigit(date[2]) == false || std::isdigit(date[3]) == false || date[4] != '-' || std::isdigit(date[5]) == false || std::isdigit(date[6]) == false || date[7] != '-' || std::isdigit(date[8]) == false || std::isdigit(date[9]) == false) {
		return (false);
	}

	const int	dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	this->_year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	this->_month = (date[5] - '0') * 10 + (date[6] - '0');
	if (this->_month < 1 || 12 < this->_month) {
		return (false);
	}
	this->_day = (date[8] - '0') * 10 + (date[9] - '0');
	if (this->_day < 1 || dayInMonth[this->_month - 1] < this->_day) {
		return (false);
	}
	return (true);
}

// Getters
int		Data::getYear(void) const { return (this->_year); }
int		Data::getMonth(void) const { return (this->_month); }
int		Data::getDay(void) const { return (this->_day); }
float	Data::getValue(void) const { return (this->_value); }

bool	Data::operator<(const Data &rhs) const {
	if (this->_year < rhs._year) {
		return (true);
	} else if (this->_year == rhs._year) {
		if (this->_month < rhs._month) {
			return (true);
		} else if (this->_month == rhs._month) {
			if (this->_day < rhs._day) {
				return (true);
			}
		}
	}
	return (false);
}

// Exception: InvalidDateError
Data::InvalidDateError::InvalidDateError(void): _msg("Invalid date") {}
Data::InvalidDateError::InvalidDateError(const std::string &date): _msg("Invalid date: " + date) {}
Data::InvalidDateError::~InvalidDateError(void) throw() {}
const char *Data::InvalidDateError::what(void) const throw() {
	return (this->_msg.c_str());
}

// Exception: NegativeValueError
Data::NegativeValueError::NegativeValueError(void): _msg("Negative value") {}
Data::NegativeValueError::NegativeValueError(const std::string &value): _msg("Negative value: " + value) {}
Data::NegativeValueError::~NegativeValueError(void) throw() {}
const char *Data::NegativeValueError::what(void) const throw() {
	return (this->_msg.c_str());
}

// Exception: UnknownError
Data::UnknownError::UnknownError(void): _msg("Unknown error") {}
Data::UnknownError::UnknownError(const std::string &line): _msg("Unknown error: " + line) {}
Data::UnknownError::~UnknownError(void) throw() {}
const char *Data::UnknownError::what(void) const throw() {
	return (this->_msg.c_str());
}

std::ostream	&operator<<(std::ostream &os, const Data &rhs) {
	std::string	year = std::to_string(rhs.getYear());
	std::string	month = std::to_string(rhs.getMonth());
	std::string	day = std::to_string(rhs.getDay());

	if (month.length() == 1) {
		month = "0" + month;
	}
	if (day.length() == 1) {
		day = "0" + day;
	}
	os << std::fixed << std::setprecision(2) << year << "-" << month << "-" << day << " " << rhs.getValue();
	return (os);
}