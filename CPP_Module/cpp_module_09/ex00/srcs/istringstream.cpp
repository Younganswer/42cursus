#include "../incs/istringstream.hpp"
#include <limits>
#include <ctype.h>

ft::istringstream::istringstream(void): std::istringstream() {}
ft::istringstream::istringstream(const std::string &str, const std::string &delim): std::istringstream(str), _delim(delim) {}
ft::istringstream::~istringstream(void) {}
ft::istringstream::istringstream(const istringstream &ref): std::istringstream(ref.str()), _delim(ref._delim) {}
ft::istringstream	&ft::istringstream::operator=(const istringstream &rhs) {
	if (this != &rhs) {
		this->~istringstream();
		new (this) istringstream(rhs);
	}
	return (*this);
}

bool	ft::istringstream::isDelim(char c) const { return (_delim.find(c) != std::string::npos); }

ft::istringstream	&ft::operator>>(ft::istringstream	&__is, std::__1::basic_string< char, std::__1::char_traits<char>, std::__1::allocator<char> >	&__str) {
	std::ios_base::iostate		__state = std::ios_base::goodbit;
	ft::istringstream::sentry	__sen(__is);
	if (__sen)
	{
	#ifndef _LIBCPP_NO_EXCEPTIONS
			try
			{
	#endif
				__str.clear();
				long int	__n = __is.width();
				if (__n <= 0)
					__n = __str.max_size();
				if (__n <= 0)
					__n = std::numeric_limits<long int>::max();
				long int	__c = 0;
				const std::ctype<char> 	&__ct = std::use_facet< std::ctype<char> >(__is.getloc());
				while (__c < __n)
				{
					std::char_traits<char>::int_type	__i = __is.rdbuf()->sgetc();
					if (std::char_traits<char>::eq_int_type(__i, std::char_traits<char>::eof()))
					{
					   __state |= std::ios_base::eofbit;
					   break;
					}
					char	__ch = std::char_traits<char>::to_char_type(__i);
					if (__ct.is(__ct.space, __ch) || __is.isDelim(__ch)) {
						while (__is.isDelim(__ch)) {
							__is.rdbuf()->sbumpc();
							__i = __is.rdbuf()->sgetc();
							if (std::char_traits<char>::eq_int_type(__i, std::char_traits<char>::eof()))
							{
							   __state |= std::ios_base::eofbit;
							   break;
							}
							__ch = std::char_traits<char>::to_char_type(__i);
						}
						break;
					}
					__str.push_back(__ch);
					++__c;
					__is.rdbuf()->sbumpc();
				}
				__is.width(0);
				if (__c == 0)
				   __state |= std::ios_base::failbit;
	#ifndef _LIBCPP_NO_EXCEPTIONS
			}
			catch (...)
			{
				__state |= std::ios_base::badbit;
				__is.__setstate_nothrow(__state);
				if (__is.exceptions() & std::ios_base::badbit)
				{
					throw;
				}
			}
	#endif
			__is.setstate(__state);
		}
		return (__is);
}