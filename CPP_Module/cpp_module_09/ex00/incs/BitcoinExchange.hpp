#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "Header.hpp"
# include <fstream>
# include <string>

class BitcoinExchange {
	private:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

	private:
		static Header	_header;
		
	public:
		static bool	exchange(const std::string &filename) throw(std::exception);
	
	private:
		static bool	_parseHeader(std::ifstream &ifs) throw(std::exception);
		static bool	_exchange(const std::string &line) throw(std::exception);

	private:
		static bool	_isInvalidValue(const std::string &value);

	public:
		class FailToOpenFileException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToParseHeaderException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToConstructHeaderException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidSyntaxException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidArgumentException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToExchangeException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class NotAPositiveNumberException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class TooLargeNumberException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif