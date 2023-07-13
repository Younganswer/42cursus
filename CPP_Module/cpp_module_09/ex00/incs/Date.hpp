#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <string>

class Date {
	private:
		int		_year;
		int		_month;
		int		_day;
	
	public:
		Date(void);
		Date(const std::string &date);
		~Date(void);
		Date(const Date &ref);
		Date	&operator=(const Date &rhs);
	
	private:
		bool	_parse(const std::string &date) throw(std::exception);
	
	private:
		static bool	_dateFormatIsNotValid(const std::string &date);
		static bool	_dateValueIsNotValid(int year, int month, int day);
	
	public:
		int	getYear(void) const;
		int	getMonth(void) const;
		int	getDay(void) const;
	
	public:
		bool	operator<(const Date &rhs) const;
	
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

std::ostream	&operator<<(std::ostream &os, const Date &date);

#endif