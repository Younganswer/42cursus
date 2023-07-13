#include "../incs/Header.hpp"
#include "../incs/istringstream.hpp"

const std::string	Header::_valid_delimeter = "\t\n\v\f\r ,|:-";
const std::string	Header::_valid_header[] = {"date", "exchange_rate", "value"};

Header::Header(void): _delimeter(), _header_map() {}
Header::Header(const std::string &line) throw(std::exception): _delimeter(), _header_map() {
	try {
		this->_parse(line);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw (FailToParseException());
	}
}
Header::~Header(void) {}
Header::Header(const Header &ref): _delimeter(ref._delimeter), _header_map(ref._header_map) {}
Header &Header::operator=(const Header &rhs) {
	if (this != &rhs) {
		this->~Header();
		new (this) Header(rhs);
	}
	return (*this);
}

bool	Header::_parse(const std::string &line) throw(std::exception) {
	try {
		this->_parseDelimeter(line);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw (FailToParseDelimeterException());
	}
	try {
		this->_parseHeaderMap(line);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw (FailToParseHeaderMapException());
	}
	return (true);
}

bool	Header::_parseDelimeter(const std::string &header) throw(std::exception) {
	for (size_t i=0; i<sizeof(Header::_valid_delimeter)/sizeof(char); ++i) {
		if (header.find(Header::_valid_delimeter[i]) != std::string::npos) {
			this->_delimeter.push_back(Header::_valid_delimeter[i]);
		}
	}
	if (this->_delimeter == "") {
		throw (InvalidArgumentException());
	}
	return (true);
}

bool	Header::_parseHeaderMap(const std::string &header) throw(std::exception) {
	std::string			token;
	ft::istringstream	iss;

	iss = ft::istringstream(header, this->_delimeter);
	while (iss >> token) {
		if (this->_isInvalidArgument(token)) {
			throw (InvalidArgumentException());
		}
		this->_header_map[this->_header_map.size()] = token;
	}
	return (true);
}

bool	Header::_isInvalidArgument(const std::string &token) {
	for (size_t i=0; i<sizeof(Header::_valid_header)/sizeof(std::string); ++i) {
		if (token == Header::_valid_header[i]) {
			return (false);
		}
	}
	return (true);
}

const std::string					&Header::getDelimeter(void) const { return (this->_delimeter); }
const std::map<size_t, std::string>	&Header::getHeaderMap(void) const { return (this->_header_map); }

std::string	&Header::operator[](size_t index) throw(std::exception) {
	HeaderMap::iterator	it = this->_header_map.find(index);

	if (it == this->_header_map.end()) {
		throw (std::out_of_range("Header: Out of range"));
	}
	return (it->second);
}

const std::string	&Header::operator[](size_t index) const throw(std::exception) {
	HeaderMap::const_iterator	it = this->_header_map.find(index);

	if (it == this->_header_map.end()) {
		throw (std::out_of_range("Header: Out of range"));
	}
	return (it->second);
}

size_t	Header::size(void) const { return (this->_header_map.size()); }

const char	*Header::FailToParseException::what(void) const throw() { return ("Header: Fail to parse"); }
const char	*Header::FailToParseDelimeterException::what(void) const throw() { return ("Header: Fail to parse delimeter"); }
const char	*Header::FailToParseHeaderMapException::what(void) const throw() { return ("Header: Fail to parse header map"); }
const char	*Header::InvalidArgumentException::what(void) const throw() { return ("Header: Invalid argument"); }

std::ostream	&operator<<(std::ostream &os, const Header &header) {
	for (size_t i=0; i<header.size(); ++i) {
		os << header[i];
		if (i != header.size() - 1) {
			os << header.getDelimeter();
		}
	}
	return (os);
}