#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert {
	private:
		static bool	possibleToConvertStringToChar(const std::string &str);
		static bool	possibleToConvertStringToInt(const std::string &str);
		static bool	possibleToConvertStringToFloat(const std::string &str);
		static bool	possibleToConvertStringToDouble(const std::string &str);
	
		static bool	parameterIsChar(const std::string &str);
		static bool	parameterIsInt(const std::string &str);
		static bool	parameterIsFloat(const std::string &str);
		static bool	parameterIsDouble(const std::string &str);

		static bool	printChar(const std::string &str);
		static bool	printInt(const std::string &str);
		static bool	printFloat(const std::string &str);
		static bool	printDouble(const std::string &str);
		
		Convert(void);
		~Convert(void);
		Convert(const Convert &ref);
		Convert	&operator=(const Convert &rhs);

	public:
		// Util
		static bool	convert(const std::string &str);
};

#endif