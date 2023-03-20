#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		static bool	handleOperator(std::stack<int> &stack, const std::string &token);

	public:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);
		RPN	&operator=(const RPN &rhs);

		static bool	operate(const std::string &arg);

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
				InvalidOperatorError(const std::string &_operator);
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
};

#endif