#include "../incs/DataBase.hpp"
#include "../incs/istringstream.hpp"

DataBase::DataBase(void): _header(), _exchange_rate_map() {
	try {
		this->_parse();
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToParseException());
	}
}
DataBase::~DataBase(void) {}
DataBase::DataBase(const DataBase &ref): _header(ref._header), _exchange_rate_map(ref._exchange_rate_map) {}
DataBase &DataBase::operator=(const DataBase &rhs) {
	if (this != &rhs) {
		this->~DataBase();
		new (this) DataBase(rhs);
	}
	return (*this);
}

bool	DataBase::_parse(void) throw(std::exception) {
	std::ifstream	ifs("./data/data.csv");

	if (!ifs.is_open()) {
		throw (FailToOpenFileException());
	}
	try {
		this->_parseHeader(ifs);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToParseHeaderException());
	}
	try {
		this->_parseValueMap(ifs);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToParseValueMapException());
	}
	return (true);
}

bool	DataBase::_parseHeader(std::ifstream &ifs) throw(std::exception) {
	std::string	line;

	if (!std::getline(ifs, line)) {
		throw (FailToParseException());
	}
	
	try {
		this->_header = Header(line);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		throw (FailToConstructHeaderException());
	}
	return (true);
}

bool	DataBase::_parseValueMap(std::ifstream &ifs) throw(std::exception) {
	std::string			line, token, date, exchange_rate;
	ft::istringstream	iss;

	while (std::getline(ifs, line)) {
		iss = ft::istringstream(line, this->_header.getDelimeter());
		for (size_t i=0; i<this->_header.size(); ++i) {
			iss >> token;
			if (this->_header[i] == "date") {
				date = token;
			} else if (this->_header[i] == "exchange_rate") {
				exchange_rate = token;
			} else {
				throw (InvalidArgumentException());
			}
		}
		if (this->_exchange_rate_map.find(Date(date)) != this->_exchange_rate_map.end()) {
			throw (DuplicatedArgumentException());
		}
		this->_exchange_rate_map.insert(std::make_pair(Date(date), ExchangeRate(exchange_rate)));
	}
	return (true);
}

const Header	&DataBase::getHeader(void) const { return (this->_header); }

DataBase	&DataBase::getInstance(void) {
	static DataBase		instance;

	return (instance);
}

DataBase::iterator			DataBase::begin(void) { return (this->_exchange_rate_map.begin()); }
DataBase::iterator			DataBase::end(void) { return (this->_exchange_rate_map.end()); }
DataBase::iterator			DataBase::find(const Date &date) { return (this->_exchange_rate_map.find(date)); }
DataBase::iterator			DataBase::lower_bound(const Date &date) { return (this->_exchange_rate_map.lower_bound(date)); }
DataBase::const_iterator	DataBase::begin(void) const { return (this->_exchange_rate_map.begin()); }
DataBase::const_iterator	DataBase::end(void) const { return (this->_exchange_rate_map.end()); }
DataBase::const_iterator	DataBase::find(const Date &date) const { return (this->_exchange_rate_map.find(date)); }
DataBase::const_iterator	DataBase::lower_bound(const Date &date) const { return (this->_exchange_rate_map.lower_bound(date)); }

const char	*DataBase::FailToOpenFileException::what(void) const throw() { return ("DataBase: Fail to open file"); }
const char	*DataBase::FailToParseException::what(void) const throw() { return ("DataBase: Fail to parse"); }
const char	*DataBase::FailToParseHeaderException::what(void) const throw() { return ("DataBase: Fail to parse header"); }
const char	*DataBase::FailToConstructHeaderException::what(void) const throw() { return ("DataBase: Fail to construct header"); }
const char	*DataBase::FailToParseValueMapException::what(void) const throw() { return ("DataBase: Fail to parse value map"); }
const char	*DataBase::InvalidArgumentException::what(void) const throw() { return ("DataBase: Invalid argument"); }
const char	*DataBase::DuplicatedArgumentException::what(void) const throw() { return ("DataBase: Duplicated argument"); }
const char	*DataBase::InvalidSyntaxException::what(void) const throw() { return ("DataBase: Invalid syntax"); }

std::ostream	&operator<<(std::ostream &os, const DataBase &rhs) {
	const Header	&header = rhs.getHeader();
	os << header;
	for (DataBase::const_iterator it=rhs.begin(); it!=rhs.end(); ++it) {
		os << std::endl << it->first << header.getDelimeter() << it->second;
	}
	return (os);
}