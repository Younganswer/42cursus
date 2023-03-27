#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		static bool	handleOperator(std::stack<int> &stack, const char token);
		static bool	throwErrorOccurredInHandleOperator(std::exception &e);

		RPN(void);
		~RPN(void);
		RPN(const RPN &ref);
		RPN	&operator=(const RPN &rhs);

	public:
		static int	operate(const std::string &arg) throw(std::exception);

		// Exception: NotEnoughOperandsError
		class NotEnoughOperandsError: public std::exception {
			private:
				std::string	_msg;

			public:
				NotEnoughOperandsError(void);
				virtual ~NotEnoughOperandsError(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: InvalidOperatorError
		class InvalidOperatorError: public std::exception {
			private:
				std::string	_msg;

			public:
				InvalidOperatorError(void);
				InvalidOperatorError(const char _operator);
				virtual ~InvalidOperatorError(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: DivideByZeroError
		class DivideByZeroError: public std::exception {
			private:
				std::string	_msg;

			public:
				DivideByZeroError(void);
				virtual ~DivideByZeroError(void) throw();
				virtual const char	*what(void) const throw();
		};
		
		// Exception: ModuloByZeroError
		class ModuloByZeroError: public std::exception {
			private:
				std::string	_msg;

			public:
				ModuloByZeroError(void);
				virtual ~ModuloByZeroError(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: InvalidExpressionError
		class InvalidExpressionError: public std::exception {
			private:
				std::string	_msg;

			public:
				InvalidExpressionError(void);
				virtual ~InvalidExpressionError(void) throw();
				virtual const char	*what(void) const throw();
		};

		// Exception: UnknownError
		class UnknownError: public std::exception {
			private:
				std::string	_msg;

			public:
				UnknownError(void);
				virtual ~UnknownError(void) throw();
				virtual const char	*what(void) const throw();
		};
};

#endif