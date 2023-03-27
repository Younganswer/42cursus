#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace {
	private:
		Replace(void);
		~Replace(void);

		// Util
		static bool	replaceLine(std::string &line, const std::string &s1, const std::string &s2);

	public:
		// Util	
		static bool	replace(const std::string &fileName, const std::string &s1, const std::string &s2);

		// Exception: FileOpenError
		class FileOpenError: public std::exception {
			private:
				std::string	_msg;

			public:
				FileOpenError(void);
				FileOpenError(const std::string &fileName);
				virtual ~FileOpenError(void) throw();
				virtual const char *what(void) const throw();
		};
};

#endif