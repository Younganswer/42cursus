#ifndef DATABASE_HPP
# define DATABASE_HPP

# include "Header.hpp"
# include "Date.hpp"
# include "ExchangeRate.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <map>

class DataBase {
	public:
		typedef std::map<Date, ExchangeRate>	ExchangeRateMap;
		typedef ExchangeRateMap::iterator		iterator;
		typedef ExchangeRateMap::const_iterator	const_iterator;
	
	private:
		Header				_header;
		ExchangeRateMap		_exchange_rate_map;

	private:
		DataBase(void);
		~DataBase(void);
		DataBase(const DataBase &ref);
		DataBase	&operator=(const DataBase &rhs);

	private:
		bool	_parse(void) throw(std::exception);
		bool	_parseHeader(std::ifstream &ifs) throw(std::exception);
		bool	_parseValueMap(std::ifstream &ifs) throw(std::exception);
	
	public:
		const Header	&getHeader(void) const;
	
	public:
		static DataBase	&getInstance(void);
	
	public:
		iterator		begin(void);
		iterator		end(void);
		iterator		find(const Date &date);
	
	public:
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
		const_iterator	find(const Date &date) const;
	
	public:
		const ExchangeRate	&at(const Date &date) const throw(std::exception);

	public:
		class FailToOpenFileException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class FailToParseException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class FailToParseHeaderException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class FailToConstructHeaderException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class FailToParseValueMapException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class InvalidArgumentException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class DuplicatedArgumentException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class InvalidSyntaxException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const DataBase &rhs);

#endif