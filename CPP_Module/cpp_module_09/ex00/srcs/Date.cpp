#include "../incs/Date.hpp"
#include "../incs/istringstream.hpp"
#include <sstream>

Date::Date(void): _year(0), _month(0), _day(0) {}
Date::Date(const std::string &date) {
	try {
		this->_parse(date);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw (FailToParseException());
	}
}
Date::~Date(void) {}
Date::Date(const Date &ref): _year(ref._year), _month(ref._month), _day(ref._day) {}
Date	&Date::operator=(const Date &rhs) {
	if (this != &rhs) {
		this->~Date();
		new (this) Date(rhs);
	}
	return (*this);
}

bool	Date::_parse(const std::string &date) throw(std::exception) {
	ft::istringstream	iss(date, "-");
	std::string			year, month, day;

	if (Date::_dateFormatIsNotValid(date)) {
		throw (InvalidArgumentException());
	}
	iss >> year >> month >> day;
	this->_year = std::atoi(year.c_str());
	this->_month = std::atoi(month.c_str());
	this->_day = std::atoi(day.c_str());
	if (Date::_dateValueIsNotValid(this->_year, this->_month, this->_day)) {
		throw (InvalidArgumentException());
	}
	return (true);
}

bool	Date::_dateFormatIsNotValid(const std::string &date) {
	if (date.length() != 10) {
		return (true);
	}
	for (size_t i=0; i<date.length(); ++i) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') {
				return (true);
			}
		} else {
			if (!std::isdigit(date[i])) {
				return (true);
			}
		}
	}
	return (false);
}

bool	Date::_dateValueIsNotValid(int year, int month, int day) {
	int	days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || 9999 < year || month < 1 || 12 < month) {
		return (true);
	}
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (day < 1 || days_in_month[month - 1] < day) {
		return (true);
	}
	return (false);
}

int	Date::getYear(void) const { return (this->_year); }
int	Date::getMonth(void) const { return (this->_month); }
int	Date::getDay(void) const { return (this->_day); }

bool	Date::operator<(const Date &rhs) const {
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

const char	*Date::FailToParseException::what(void) const throw() { return ("Date: Fail to parse"); }
const char	*Date::InvalidArgumentException::what(void) const throw() { return ("Date: Invalid argument"); }

std::ostream	&operator<<(std::ostream &os, const Date &date) {
	os << date.getYear();
	os << "-";
	os << ((date.getMonth() < 10) ? "0" : "") << date.getMonth();
	os << "-";
	os << ((date.getDay() < 10) ? "0" : "") << date.getDay();
	return (os);
}