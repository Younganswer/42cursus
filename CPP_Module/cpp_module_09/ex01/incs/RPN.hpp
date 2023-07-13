#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		RPN(void);
		~RPN(void);
		RPN(const RPN &ref);
		RPN	&operator=(const RPN &rhs);

	private:
		static bool	handleOperator(std::stack<int> &stack, const char token);

	public:
		static int	operate(const std::string &arg) throw(std::exception);

	public:
		class NotEnoughOperandsException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidOperatorException: public std::exception {
			private:
				std::string	_msg;
			public:
				InvalidOperatorException(const char _operator);
				virtual	~InvalidOperatorException(void) throw();
				virtual const char	*what(void) const throw();
		};
		class DivideByZeroException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class ModuloByZeroException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidExpressionException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToHandleOperatorException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif