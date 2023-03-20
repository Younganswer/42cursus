#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data {
	private:
		int		_year;
		int		_month;
		int		_day;
		float	_value;

		bool	parseDate(const std::string &date);

	public:
		Data(void);
		Data(const std::string &line) throw(std::exception);
		Data(const std::string &line, int delim) throw(std::exception);
		Data(const Data &ref);
		~Data(void);
		Data	&operator=(const Data &rhs);

		// Getter
		int		getYear(void) const;
		int		getMonth(void) const;
		int		getDay(void) const;
		float	getValue(void) const;

		// overload
		bool	operator<(const Data &rhs) const;

		// Exception: InvalidDateError
		class InvalidDateError: public std::exception {
			private:
				std::string	_msg;

			public:
				InvalidDateError(void);
				InvalidDateError(const std::string &date);
				virtual ~InvalidDateError(void) throw();
				virtual const char *what(void) const throw();
		};

		// Exception: NegativeValueError
		class NegativeValueError: public std::exception {
			private:
				std::string	_msg;

			public:
				NegativeValueError(void);
				NegativeValueError(const std::string &value);
				virtual ~NegativeValueError(void) throw();
				virtual const char *what(void) const throw();
		};

		// Exception: UnknownError
		class UnknownError: public std::exception {
			private:
				std::string	_msg;

			public:
				UnknownError(void);
				UnknownError(const std::string &value);
				virtual ~UnknownError(void) throw();
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Data &ref);

#endif