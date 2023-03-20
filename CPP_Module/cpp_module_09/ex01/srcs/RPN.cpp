#include "../incs/RPN.hpp"
#include <sstream>

RPN::RPN(void) {}
RPN::RPN(const RPN &src) { *this = src; }
RPN::~RPN(void) {}
RPN	&RPN::operator=(const RPN &rhs) {
	(void) rhs;
	return (*this);
}

bool	RPN::handleOperator(std::stack<int> &st, const std::string &token) {
	if (st.size() < 2) {
		throw (RPN::NotEnoughOperandsError());
	}
	
	int	left, right, value;

	right = st.top();
	st.pop();
	left = st.top();
	st.pop();
	if (token == "+") {
		value = left + right;
	} else if (token == "-") {
		value = left - right;
	} else if (token == "*") {
		value = left * right;
	} else if (token == "/") {
		if (right == 0) {
			throw (RPN::DivideByZeroError());
		}
		value = left / right;
	} else if (token == "%") {
		if (right == 0) {
			throw (RPN::ModuloByZeroError());
		}
		value = left % right;
	} else {
		throw (RPN::InvalidOperatorError(token));
	}
	st.push(value);
	return (true);
}

bool	RPN::operate(const std::string &arg) {
	std::stack<int>		st;
	std::stringstream	ss(arg);
	std::string			token;

	while (ss.eof() == false) {
		ss >> token;
		if (token.empty()) {
			continue;
		}
		if (1 < token.length()) {
			std::cerr << "\033[31m" << "Error: " << "Invalid argument: " << token << "\033[0m" << '\n';
			return (false);
		}

		if (std::isdigit(token[0]) == false) {
			try {
				handleOperator(st, token);
			} catch (std::exception &e) {
				std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
				return (false);
			} catch (...) {
				std::cerr << "\033[31m" << "Error: " << "Unknown error" << "\033[0m" << '\n';
				return (false);
			}
		} else {
			try {
				st.push(std::stoi(token));
			} catch (std::exception &e) {
				std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
				return (false);
			} catch (...) {
				std::cerr << "\033[31m" << "Error: " << "Unknown error" << "\033[0m" << '\n';
				return (false);
			}
		}
	}
	if (st.size() != 1) {
		std::cerr << "\033[31m" << "Error: " << "Not enough operands" << "\033[0m" << '\n';
		return (false);
	}
	std::cout << st.top() << '\n';
	return (true);
}

// Exception: NotEnoughOperandsError
RPN::NotEnoughOperandsError::NotEnoughOperandsError(void): _msg("Not enough operands") {}
RPN::NotEnoughOperandsError::~NotEnoughOperandsError(void) throw() {}
const char	*RPN::NotEnoughOperandsError::what(void) const throw() {
	return (_msg.c_str());
}

// Exception: InvalidOperatorError
RPN::InvalidOperatorError::InvalidOperatorError(void): _msg("Invalid operator") {}
RPN::InvalidOperatorError::InvalidOperatorError(const std::string &_operator): _msg("Invalid operator: " + _operator) {}
RPN::InvalidOperatorError::~InvalidOperatorError(void) throw() {}
const char	*RPN::InvalidOperatorError::what(void) const throw() {
	return (_msg.c_str());
}

// Exception: DivideByZeroError
RPN::DivideByZeroError::DivideByZeroError(void): _msg("Divide by zero") {}
RPN::DivideByZeroError::~DivideByZeroError(void) throw() {}
const char	*RPN::DivideByZeroError::what(void) const throw() {
	return (_msg.c_str());
}

// Exception: ModuloByZeroError
RPN::ModuloByZeroError::ModuloByZeroError(void): _msg("Modulo by zero") {}
RPN::ModuloByZeroError::~ModuloByZeroError(void) throw() {}
const char	*RPN::ModuloByZeroError::what(void) const throw() {
	return (_msg.c_str());
}