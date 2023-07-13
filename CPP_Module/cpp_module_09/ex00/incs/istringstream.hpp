#ifndef ISTRINGSTREAM_HPP
# define ISTRINGSTREAM_HPP

# include <string>
# include <iostream>
# include <sstream>

namespace ft {

class istringstream: public std::istringstream {
	private:
		std::string	_delim;

	public:
		istringstream(void);
		istringstream(const std::string &str, const std::string &delim=" \t\n\v\f\r,|");
		~istringstream(void);
		istringstream(const istringstream &ref);
		istringstream	&operator=(const istringstream &rhs);
	
	public:
		bool	isDelim(char c) const;
};

istringstream	&operator>>(ft::istringstream	&__is, std::__1::basic_string< char, std::__1::char_traits<char>, std::__1::allocator<char> >	&__str);

};

#endif