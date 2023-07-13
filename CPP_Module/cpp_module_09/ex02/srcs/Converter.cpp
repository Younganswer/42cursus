#include "../incs/Converter.hpp"
#include <string>

Converter::Converter(void) {}
Converter::~Converter(void) {}
Converter::Converter(Converter const &other) { (void)other; }
Converter &Converter::operator=(Converter const &other) { (void)other; return (*this); }

int	Converter::convert(const char *arg) throw(std::exception) {
	int						ret;
	std::string				str(arg);
	std::string::iterator	it = str.begin();

	while (it!=str.end() && std::isspace(*it)) {
		it++;
	}
	str.erase(str.begin(), it);	
	it = str.begin();
	if (*it == '+' || *it == '-') {
		it++;
	}
	while (it != str.end()) {
		if (!std::isdigit(*it)) {
			throw (InvalidInputException());
		}
		it++;
	}
	ret = std::atoi(str.c_str());
	if (ret < 0) {
		throw (NegativeValueException());
	}
	return (ret);
}

const char *Converter::InvalidInputException::what(void) const throw() { return ("Converter: Invalid input"); }
const char *Converter::NegativeValueException::what(void) const throw() { return ("Converter: Negative value"); }