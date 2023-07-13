#include "../incs/RPN.hpp"
#include <sstream>

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN::RPN(const RPN &ref) { (void) ref; }
RPN	&RPN::operator=(const RPN &rhs) {
	(void) rhs;
	return (*this);
}

bool	RPN::handleOperator(std::stack<int> &st, const char token) {
	int	left, right, value;
	
	if (token != '+' && token != '-' && token != '*' && token != '/' && token != '%') {
		throw (RPN::InvalidOperatorException(token));
	}
	if (st.size() < 2) {
		throw (RPN::NotEnoughOperandsException());
	}
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
			throw (RPN::DivideByZeroException());
		}
		value = left / right;
	} else if (token == '%') {
		if (right == 0) {
			throw (RPN::ModuloByZeroException());
		}
		value = left % right;
	}
	st.push(value);
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
			} catch (const std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
				throw (FailToHandleOperatorException());
			}
		} else {
			st.push(arg[i] - '0');
		}
	}
	if (st.size() != 1) {
		throw (RPN::InvalidExpressionException());
	}
	return (st.top());
}

const char	*RPN::NotEnoughOperandsException::what(void) const throw() { return ("RPN: Not enough operands"); }
RPN::InvalidOperatorException::InvalidOperatorException(const char _operator): _msg(std::string("RPN: Invalid operator: ") + _operator) {}
RPN::InvalidOperatorException::~InvalidOperatorException(void) throw() {}
const char	*RPN::InvalidOperatorException::what(void) const throw() { return (_msg.c_str()); }
const char	*RPN::DivideByZeroException::what(void) const throw() {return ("RPN: Divide by zero"); }
const char	*RPN::ModuloByZeroException::what(void) const throw() { return ("RPN: Modulo by zero"); }
const char	*RPN::InvalidExpressionException::what(void) const throw() { return ("RPN: Invalid expression"); }
const char	*RPN::FailToHandleOperatorException::what(void) const throw() { return ("RPN: Fail to handle operator"); }