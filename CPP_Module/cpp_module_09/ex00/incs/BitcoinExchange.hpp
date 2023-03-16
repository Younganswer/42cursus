#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <string>

class BitcoinExchange {
	private:
		std::string		_filename;

		BitcoinExchange(void);

	public:
		BitcoinExchange(const std::string &filename) throw(std::exception);
		BitcoinExchange(const BitcoinExchange &ref);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs) throw(std::exception);

		// Util
		bool	print(void) const;

		// Exception: FileOpenError
		class FileOpenError : public std::exception {
			private:
				std::string	_msg;

			public:
				FileOpenError(void);
				FileOpenError(const std::string &filename);
				~FileOpenError(void) throw();
				virtual const char *what(void) const throw();
		};
};

#endif