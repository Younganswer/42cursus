#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace {
	private:
		std::string	_fileName;
		std::string	_s1;
		std::string	_s2;

		// Util
		bool	replaceLine(std::string &line);

	public:
		Replace(void);
		Replace(const std::string &fileName, const std::string &s1, const std::string &s2);
		~Replace(void);

		// Util	
		bool	replace(void);
};

#endif