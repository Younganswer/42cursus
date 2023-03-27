#include "../incs/Convert.hpp"
#include <iostream>
#include <ctype.h>
#include <cmath>

Convert::Convert(void) {}
Convert::~Convert(void) {}
Convert::Convert(const Convert &ref) { (void) ref; }
Convert	&Convert::operator=(const Convert &rhs) { (void) rhs; return (*this); }

bool	Convert::possibleToConvertStringToChar(const std::string &str) {
	double	d = std::stod(str);

	return (CHAR_MIN <= d && d <= CHAR_MAX);
}

bool	Convert::possibleToConvertStringToInt(const std::string &str) {
	double	d = std::stod(str);

	return (INT_MIN <= d && d <= INT_MAX);
}

bool	Convert::possibleToConvertStringToFloat(const std::string &str) {
	double	d = std::stod(str);

	return (FLT_MIN <= d && d <= FLT_MAX);
}

bool	Convert::possibleToConvertStringToDouble(const std::string &str) {
	try {
		double	d = std::stod(str);

		(void) d;
	} catch (std::exception &e) {
		return (false);
	}
	return (true);
}

bool	Convert::parameterIsChar(const std::string &str) {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool	Convert::parameterIsInt(const std::string &str) {
	size_t	i=0, j;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	for (j=i; j<str.length(); j++) {
		if (std::isdigit(str[j]) == false) {
			return (false);
		}
	}
	return (0 < j - i);
}

bool	Convert::parameterIsFloat(const std::string &str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") {
		return (true);
	}

	size_t	i=0, j;
	bool	has_dot = false;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	for (j=i; j<str.length()-1; j++) {
		if (str[j] == '.') {
			if (has_dot) {
				return (false);
			}
			has_dot = true;
		} else if (std::isdigit(str[j]) == false) {
			return (false);
		}
	}
	return ((0 < j - i) && has_dot && (str[j] == 'f'));
}

bool	Convert::parameterIsDouble(const std::string &str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
		return (true);
	}
	
	size_t	i=0, j;
	bool	has_dot = false;

	while (std::isspace(str[i])) {
		i++;
	}
	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	for (j=i; j<str.length(); j++) {
		if (str[j] == '.') {
			if (has_dot) {
				return (false);
			}
			has_dot = true;
		} else if (std::isdigit(str[j]) == false) {
			return (false);
		}
	}
	return ((0 < j - i) && has_dot && str[j - 1] != '.');
}

bool	Convert::printChar(const std::string &str) {
	char	ch = str[0];
	int		i = static_cast<int>(ch);
	float	f = static_cast<float>(ch);
	double	d = static_cast<double>(ch);

	std::cout << "char: " << "'" << ch << "'" << '\n';
	std::cout << "int: " << i << '\n';
	std::cout << "float: " << f << "f" << '\n';
	std::cout << "double: " << d << '\n';
	return (true);
}

bool	Convert::printInt(const std::string &str) {
	char	ch;
	int		i;
	float	f;
	double	d;

	if (possibleToConvertStringToDouble(str)) {
		if (possibleToConvertStringToFloat(str)) {
			if (possibleToConvertStringToInt(str)) {
				i = std::stoi(str);
				f = static_cast<float>(i);
				d = static_cast<double>(i);

				if (possibleToConvertStringToChar(str)) {
					ch = static_cast<char>(i);

					std::cout << "char: ";
					if (32 <= i && i <= 126) {
						std::cout << "'" << ch << "'" << '\n';
					} else {
						std::cout << "Non displayable" << '\n';
					}
				} else {
					std::cout << "char: impossible" << '\n';
				}
				std::cout << "int: " << i << '\n';
				std::cout << "float: " << f << "f" << '\n';
				std::cout << "double: " << d << '\n';
			} else {
				std::cout << "char: impossible" << '\n';
				std::cout << "int: impossible" << '\n';
				std::cout << "float: " << std::stof(str) << "f" << '\n';
				std::cout << "double: " << std::stod(str) << '\n';
			}
		} else {
			std::cout << "char: impossible" << '\n';
			std::cout << "int: impossible" << '\n';
			std::cout << "float: impossible" << '\n';
			std::cout << "double: " << std::stod(str) << '\n';
		}
	} else {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
	}
	return (true);
}

bool	Convert::printFloat(const std::string &str) {
	char	ch;
	int		i;
	float	f;
	double	d;

	if (possibleToConvertStringToDouble(str)) {
		if (possibleToConvertStringToFloat(str)) {
			f = std::stof(str);
			d = static_cast<double>(f);

			if (possibleToConvertStringToInt(str)) {
				i = static_cast<int>(f);

				if (possibleToConvertStringToChar(str)) {
					ch = static_cast<char>(f);

					std::cout << "char: ";
					if (32 <= i && i <= 126) {
						std::cout << "'" << ch << "'" << '\n';
					} else {
						std::cout << "Non displayable" << '\n';
					}
				} else {
					std::cout << "char: impossible" << '\n';
				}
				std::cout << "int: " << i << '\n';
			} else {
				std::cout << "char: impossible" << '\n';
				std::cout << "int: impossible" << '\n';
			}
			std::cout << "float: " << f << "f" << '\n';
			std::cout << "double: " << d << '\n';
		} else {
			std::cout << "char: impossible" << '\n';
			std::cout << "int: impossible" << '\n';
			std::cout << "float: impossible" << '\n';
			std::cout << "double: " << std::stod(str) << '\n';
		}
	} else {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
	}
	return (true);
}

bool	Convert::printDouble(const std::string &str) {
	char	ch;
	int		i;
	float	f;
	double	d;

	if (possibleToConvertStringToDouble(str)) {
		d = std::stod(str);

		if (possibleToConvertStringToFloat(str)) {
			f = static_cast<float>(d);

			if (possibleToConvertStringToInt(str)) {
				i = static_cast<int>(d);

				if (possibleToConvertStringToChar(str)) {
					ch = static_cast<char>(d);

					std::cout << "char: ";
					if (32 <= i && i <= 126) {
						std::cout << "'" << ch << "'" << '\n';
					} else {
						std::cout << "Non displayable" << '\n';
					}
				} else {
					std::cout << "char: impossible" << '\n';
				}
				std::cout << "int: " << i << '\n';
			} else {
				std::cout << "char: impossible" << '\n';
				std::cout << "int: impossible" << '\n';
			}
			std::cout << "float: " << f << "f" << '\n';
		} else {
			std::cout << "char: impossible" << '\n';
			std::cout << "int: impossible" << '\n';
			std::cout << "float: impossible" << '\n';
		}
		std::cout << "double: " << d << '\n';
	} else {
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
	}
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