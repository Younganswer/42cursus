#ifndef EXCHANGERATE_HPP
# define EXCHANGERATE_HPP

# include <iostream>
# include <string>

class ExchangeRate {
	private:
		double		_rate;
	
	public:
		ExchangeRate(void);
		ExchangeRate(const std::string &rate);
		~ExchangeRate(void);
		ExchangeRate(const ExchangeRate &ref);
		ExchangeRate	&operator=(const ExchangeRate &rhs);
	
	private:
		bool	_parse(const std::string &rate) throw(std::exception);

	public:
		double	getRate(void) const;
	
	public:
		class FailToParseException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidArgumentException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const ExchangeRate &rate);

#endif