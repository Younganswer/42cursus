#include "../incs/ExchangeRate.hpp"

ExchangeRate::ExchangeRate(void): _rate(0) {}
ExchangeRate::ExchangeRate(const std::string &rate) {
	try {
		this->_parse(rate);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw (FailToParseException());
	}
}
ExchangeRate::~ExchangeRate(void) {}
ExchangeRate::ExchangeRate(const ExchangeRate &ref): _rate(ref._rate) {}
ExchangeRate	&ExchangeRate::operator=(const ExchangeRate &rhs) {
	if (this != &rhs) {
		this->~ExchangeRate();
		new (this) ExchangeRate(rhs);
	}
	return (*this);
}

bool	ExchangeRate::_parse(const std::string &rate) throw(std::exception) {
	bool	dot = false;

	for (size_t j=0; j<rate.size(); j++) {
		if (rate[j] == '.') {
			if (dot) {
				throw (InvalidArgumentException());
			}
			dot = true;
			continue ;
		}
		if (!std::isdigit(rate[j])) {
			throw (InvalidArgumentException());
		}
	}
	this->_rate = std::atof(rate.c_str());
	return (true);
}

double	ExchangeRate::getRate(void) const { return (this->_rate); }

const char	*ExchangeRate::FailToParseException::what(void) const throw() { return ("ExchangeRate: Fail to parse"); }
const char	*ExchangeRate::InvalidArgumentException::what(void) const throw() { return ("ExchangeRate: Invalid argument"); }

std::ostream	&operator<<(std::ostream &os, const ExchangeRate &rate) {
	os << rate.getRate();
	return (os);
}