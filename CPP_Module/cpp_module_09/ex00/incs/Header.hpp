#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>
# include <map>

class Header {
	private:
		static const std::string	_valid_delimeter;
		static const std::string	_valid_header[];
	
	private:
		typedef std::map<size_t, std::string>	HeaderMap;
		typedef HeaderMap::iterator				iterator;
		typedef HeaderMap::const_iterator		const_iterator;
	
	public:
		Header(void);
		Header(const std::string &line) throw(std::exception);
		~Header(void);
		Header(const Header &ref);
		Header	&operator=(const Header &rhs);
	
	private:
		std::string	_delimeter;
		HeaderMap	_header_map;
	
	private:
		bool	_parse(const std::string &line) throw(std::exception);
		bool	_parseDelimeter(const std::string &header) throw(std::exception);
		bool	_parseHeaderMap(const std::string &header) throw(std::exception);
	
	private:
		static bool	_isInvalidArgument(const std::string &arg);
	
	public:
		const std::string	&getDelimeter(void) const;
		const HeaderMap		&getHeaderMap(void) const;
	
	public:
		std::string			&operator[](size_t index) throw(std::exception);
		const std::string	&operator[](size_t index) const throw(std::exception);
	
	public:
		size_t				size(void) const;
	
	public:
		class FailToParseException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToParseDelimeterException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class FailToParseHeaderMapException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class InvalidArgumentException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Header &header);

#endif