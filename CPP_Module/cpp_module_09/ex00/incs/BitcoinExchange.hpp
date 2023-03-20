#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <string>
# include <queue>

typedef struct	_Info {
	std::string	date;
	float		value;

	_Info(const std::string &date, float value);
}	Info;

class BitcoinExchange {
	private:
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

		static bool	openFile(std::ifstream &ifs, const std::string &filename);
		static bool	initializeQueue(std::queue<Info> &info_q, std::ifstream &ifs) throw(std::exception);
		static bool	invalidDate(const std::string &date);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		// Util
		static bool	exchange(const std::string &filename);

		// Exception: FileOpenError
		class FileOpenError : public std::exception {
			private:
				std::string	_msg;

			public:
				FileOpenError(void);
				FileOpenError(const std::string &filename);
				virtual ~FileOpenError(void) throw();
				virtual const char *what(void) const throw();
		};

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
		
		// Exception: InvalidFormatError
		class InvalidFormatError: public std::exception {
			private:
				std::string	_msg;

			public:
				InvalidFormatError(void);
				InvalidFormatError(const std::string &delimeter);
				virtual ~InvalidFormatError(void) throw();
				virtual const char *what(void) const throw();
		};

		// Exception: NegativeNumberError
		class NegativeNumberError: public std::exception {
			private:
				std::string	_msg;

			public:
				NegativeNumberError(void);
				NegativeNumberError(float number);
				virtual ~NegativeNumberError(void) throw();
				virtual const char *what(void) const throw();
		};

		// Exception: TooLargeNumberError
		class TooLargeNumberError: public std::exception {
			private:
				std::string	_msg;

			public:
				TooLargeNumberError(void);
				TooLargeNumberError(float number);
				virtual ~TooLargeNumberError(void) throw();
				virtual const char *what(void) const throw();
		};
};

#endif