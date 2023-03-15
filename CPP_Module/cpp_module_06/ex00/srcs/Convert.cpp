#include "../incs/Convert.hpp"
#include <iostream>
#include <ctype.h>
#include <cmath>

Convert::Convert(void) {}
Convert::Convert(const Convert &ref) { *this = ref; }
Convert	&Convert::operator=(const Convert &rhs) { (void) rhs; return (*this); }
Convert::~Convert(void) {}

bool	Convert::parameterIsChar(const std::string &str) {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool	Convert::parameterIsInt(const std::string &str) {
	size_t	i = 0;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	while (i < str.length()) {
		if (std::isdigit(str[i]) == false) {
			return (false);
		}
		i++;
	}
	return (std::isdigit(str[i - 1]));
}

bool	Convert::parameterIsFloat(const std::string &str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") {
		return (true);
	}

	size_t	i = 0;
	bool	has_dot = false;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	while (i < str.length() - 1) {
		if (str[i] == '.') {
			if (has_dot) {
				return (false);
			}
			has_dot = true;
		} else if (std::isdigit(str[i]) == false) {
			return (false);
		}
		i++;
	}
	return (has_dot && (0 < i) && (str[i] == 'f'));
}

bool	Convert::parameterIsDouble(const std::string &str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
		return (true);
	}
	
	size_t	i = 0;
	bool	has_dot = false;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	while (i < str.length()) {
		if (str[i] == '.') {
			if (has_dot) {
				return (false);
			}
			has_dot = true;
		} else if (std::isdigit(str[i]) == false) {
			return (false);
		}
		i++;
	}
	return (has_dot && std::isdigit(str[i - 1]));
}

bool	Convert::printDouble(const std::string &str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: " << str << 'f' << '\n';
		std::cout << "double: " << str << '\n';
		return (true);
	}

	double	d;
	char	ch;
	int		i;
	float	f;

	try {
		d = std::stod(str);
	} catch (std::exception &e) {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
		return (true);
	}
	ch = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	std::cout << "char: ";
	if (d < 0 || 256 <= d) {
		std::cout << "impossible" << '\n';
	} else if (std::isprint(ch) == false) {
		std::cout << "Non displayable" << '\n';
	} else {
		std::cout << "'" << ch << "'" << '\n';
	}
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << 'f' << '\n';
	std::cout << "double: " << d << '\n';
	return (true);
}

bool	Convert::printFloat(const std::string &str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: " << str << '\n';
		std::cout << "double: " << str.substr(0, str.length() - 1) << '\n';
		return (true);
	}

	float	f;
	char	ch;
	int		i;
	double	d;

	try {
		f = std::stof(str);
	} catch (std::exception &e) {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
		return (true);
	}
	ch = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

	std::cout << "char: ";
	if (f < 0 || 256 <= f) {
		std::cout << "impossible" << '\n';
	} else if (std::isprint(ch) == false) {
		std::cout << "Non displayable" << '\n';
	} else {
		std::cout << "'" << ch << "'" << '\n';
	}
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << 'f' << '\n';
	std::cout << "double: " << d << '\n';
	return (true);
}

bool	Convert::printInt(const std::string &str) {
	int		i;
	char	ch;
	float	f;
	double	d;

	try {
		i = std::stoi(str);
	} catch (std::exception &e) {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
		return (true);
	}
	ch = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	std::cout << "char: ";
	if (i < 0 || 256 <= i) {
		std::cout << "impossible" << '\n';
	} else if (std::isprint(ch) == false) {
		std::cout << "Non displayable" << '\n';
	} else {
		std::cout << "'" << ch << "'" << '\n';
	}
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << 'f' << '\n';
	std::cout << "double: " << d << '\n';
	return (true);
}

bool	Convert::printChar(const std::string &str) {
	char	ch = static_cast<char>(str[0]);
	int		i = static_cast<int>(ch);
	float	f = static_cast<float>(ch);
	double	d = static_cast<double>(ch);

	std::cout << "char: " << ch << '\n';
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << 'f' << '\n';
	std::cout << "double: " << d << '\n';
	return (true);
}

bool	Convert::convert(const std::string &str) {
	if (parameterIsDouble(str)) {
		printDouble(str);
	} else if (parameterIsFloat(str)) {
		printFloat(str);
	} else if (parameterIsInt(str)) {
		printInt(str);
	} else if (parameterIsChar(str)) {
		printChar(str);
	} else {
		std::cerr << "\033[31m" << "Error: Invalid parameter" << "\33[0m" << '\n';
		return (false);
	}
	return (true);
}