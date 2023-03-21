#include "../incs/RPN.hpp"
#include <sstream>

RPN::RPN(void) {}
RPN::RPN(const RPN &src) { *this = src; }
RPN::~RPN(void) {}
RPN	&RPN::operator=(const RPN &rhs) {
	(void) rhs;
	return (*this);
}

bool	RPN::handleOperator(std::stack<int> &st, const char token) {
	if (token != '+' && token != '-' && token != '*' && token != '/' && token != '%') {
		throw (RPN::InvalidOperatorError(token));
	}
	if (st.size() < 2) {
		throw (RPN::NotEnoughOperandsError());
	}
	
	int	left, right, value;

	right = st.top();
	st.pop();
	left = st.top();
	st.pop();
	if (token == '+') {
		value = left + right;
	} else if (token == '-') {
		value = left - right;
	} else if (token == '*') {
		value = left * right;
	} else if (token == '/') {
		if (right == 0) {
			throw (RPN::DivideByZeroError());
		}
		value = left / right;
	} else if (token == '%') {
		if (right == 0) {
			throw (RPN::ModuloByZeroError());
		}
		value = left % right;
	}
	st.push(value);
	return (true);
}

bool	RPN::throwErrorOccurredInHandleOperator(std::exception &e) {
	if (const RPN::NotEnoughOperandsError *err_ptr1 = dynamic_cast<const RPN::NotEnoughOperandsError *>(&e)) {
		throw (*err_ptr1);
	} else if (const RPN::InvalidOperatorError *err_ptr2 = dynamic_cast<const RPN::InvalidOperatorError *>(&e)) {
		throw (*err_ptr2);
	} else if (const RPN::DivideByZeroError *err_ptr3 = dynamic_cast<const RPN::DivideByZeroError *>(&e)) {
		throw (*err_ptr3);
	} else if (const RPN::ModuloByZeroError *err_ptr4 = dynamic_cast<const RPN::ModuloByZeroError *>(&e)) {
		throw (*err_ptr4);
	} else {
		throw (RPN::UnknownError());
	}
	return (true);
}

int	RPN::operate(const std::string &arg) throw(std::exception) {
	std::stack<int>		st;

	for (size_t i=0; i<arg.length(); i++) {
		if (std::isspace(arg[i])) {
			continue;
		}
		
		if (std::isdigit(arg[i]) == false) {
			try {
				handleOperator(st, arg[i]);
			} catch (std::exception &e) {
				throwErrorOccurredInHandleOperator(e);
			} catch (...) {
				throw (RPN::UnknownError());
			}
		} else {
			try {
				st.push(arg[i] - '0');
			} catch (std::exception &e) {
				throw (e);
			} catch (...) {
				throw (RPN::UnknownError());
			}
		}
	}
	if (st.size() != 1) {
		throw (RPN::InvalidExpressionError());
	}
	return (st.top());
}

// Exception: NotEnoughOperandsError
RPN::NotEnoughOperandsError::NotEnoughOperandsError(void): _msg("Not enough operands") {}
RPN::NotEnoughOperandsError::~NotEnoughOperandsError(void) throw() {}
const char	*RPN::NotEnoughOperandsError::what(void) const throw() {
	return (_msg.c_str());
}

// Exception: InvalidOperatorError
RPN::InvalidOperatorError::InvalidOperatorError(void): _msg("Invalid operator") {}
RPN::InvalidOperatorError::InvalidOperatorError(const char _operator): _msg(std::string("Invalid operator: ") + _operator) {}
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

// Exception: InvalidExpressionError
RPN::InvalidExpressionError::InvalidExpressionError(void): _msg("Invalid expression") {}
RPN::InvalidExpressionError::~InvalidExpressionError(void) throw() {}
const char	*RPN::InvalidExpressionError::what(void) const throw() {
	return (_msg.c_str());
}

// Exception: UnknownError
RPN::UnknownError::UnknownError(void): _msg("Unknown error") {}
RPN::UnknownError::~UnknownError(void) throw() {}
const char	*RPN::UnknownError::what(void) const throw() {
	return (_msg.c_str());
}