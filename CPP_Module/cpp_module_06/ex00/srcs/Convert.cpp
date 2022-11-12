/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:23:52 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/12 21:38:13 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Convert.hpp"
#include <math.h>

Convert::Convert(void) {}

Convert::Convert(const std::string &str) {
	this->_is_nanf = false;
	this->_is_positive_inff = false;
	this->_is_negative_inff = false;
	this->_is_nan = false;
	this->_is_positive_inf = false;
	this->_is_negative_inf = false;
	this->convert(str);
}

Convert::Convert(const Convert &ref) {
	*this = ref;
}

Convert	&Convert::operator=(const Convert &rhs) {
	this->convert(rhs._str);
	return (*this);
}

Convert::~Convert(void) {}

bool	Convert::parameterIsChar(const std::string &str) {
	return (str.length() == 1 && isprint(str[0]));
}

bool	Convert::parameterIsInt(const std::string &str) {
	try {
		this->_int = std::stoi(str);
		return (true);
	} catch (std::exception &e) {
		return (false);
	}
}

bool	Convert::parameterIsFloat(const std::string &str) {
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") {
		return (true);
	}

	size_t	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;

	bool	has_dot = false;
	for (; i<str.length()-1; i++) {
		if (str[i] == '.') {
			if (!has_dot) {
				has_dot = true;
				continue;
			} else {
				return (false);
			}
		}
		if (!isdigit(str[i])) {
			return (false);
		}
	}
	return (str[str.length()-1] == 'f');
}

bool	Convert::parameterIsDouble(const std::string &str) {
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") {
		return (true);
	}
	
	size_t	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
		
	bool	has_dot = false;
	for (; i<str.length(); i++) {
		if (str[i] == '.') {
			if (!has_dot) {
				has_dot = true;
				continue;
			} else {
				return (false);
			}
		}
		if (!isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

void	Convert::convert(const std::string &str) {
	this->_str = std::string(str.c_str());
	if (parameterIsFloat(str)) {
		this->_float = std::stof(str);
		if (isnan(this->_float)) {
			this->_is_nanf = true;
		} else if (isinf(this->_float)) {
			if (this->_float > 0) {
				this->_is_positive_inff = true;
			} else {
				this->_is_negative_inff = true;
			}
		} else {
			this->_int = static_cast<int>(this->_float);
			this->_char = static_cast<char>(this->_float);
			this->_double = static_cast<double>(this->_float);
		}
	} else if (parameterIsDouble(str)) {
		this->_double = std::stod(str);
		if (isnan(this->_double)) {
			this->_is_nan = true;
		} else if (isinf(this->_double)) {
			if (this->_double > 0) {
				this->_is_positive_inf = true;
			} else {
				this->_is_negative_inf = true;
			}
		} else {
			this->_int = static_cast<int>(this->_double);
			this->_char = static_cast<char>(this->_double);
			this->_float = static_cast<float>(this->_double);
		}
	} else if (parameterIsInt(str)) {
		this->_int = std::stoi(str);
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	} else if (parameterIsChar(str)) {
		this->_char = str[0];
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
	} else {
		std::cerr << "\033[31mError: Invalid argument\033[0m" << '\n';
		exit(1);
	}
}

void	Convert::print(void) {
	std::cout << "char: ";
	if (this->_is_nanf || this->_is_positive_inff || this->_is_negative_inff) {
		std::cout << "impossible" << '\n';
	} else if (this->_double < -2147483648.95 || 2147483647.95 <= this->_double) {
		std::cout << "impossible" << '\n';
	} else if (std::isprint(this->_char)) {
		std::cout << "'" << this->_char << "'" << '\n';
	} else {
		std::cout << "Non displayable" << '\n';
	}
	std::cout << "int: ";
	if (this->_is_nanf || this->_is_positive_inff || this->_is_negative_inff) {
		std::cout << "impossible" << '\n';
	} else if (this->_double < -2147483648.95 || 2147483647.95 <= this->_double) {
		std::cout << "impossible" << '\n';
	} else {
		std::cout << this->_int << '\n';
	}
	std::cout << "float: ";
	if (this->_is_nanf) {
		std::cout << "nanf" << '\n';
	} else if (this->_is_positive_inff) {
		std::cout << "+inff" << '\n';
	} else if (this->_is_negative_inff) {
		std::cout << "-inff" << '\n';
	} else {
		std::cout << this->_float << 'f' << '\n';
	}
	std::cout << "double: ";
	if (this->_is_nan) {
		std::cout << "nan" << '\n';
	} else if (this->_is_positive_inf) {
		std::cout << "+inf" << '\n';
	} else if (this->_is_negative_inf) {
		std::cout << "-inf" << '\n';
	} else {
		std::cout << this->_double << '\n';
	}
}