#include "../incs/Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(void) {}
Span::~Span(void) {}
Span::Span(unsigned int n): _size(n) {}
Span::Span(const Span &ref): _size(ref._size) {
	for (size_t i=0; i<ref._vec.size(); i++) {
		this->_vec.push_back(ref._vec[i]);
	}
}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->~Span();
		new (this) Span(rhs);
	}
	return (*this);
}

// Iterator
Span::iterator			Span::begin(void) { return (this->_vec.begin()); }
Span::iterator			Span::end(void) { return (this->_vec.end()); }
Span::const_iterator	Span::cbegin(void) const { return (this->_vec.cbegin()); }
Span::const_iterator	Span::cend(void) const { return (this->_vec.cend()); }

bool	Span::hasDuplicated(int num) const {
	for (size_t i=0; i<this->_vec.size(); i++) {
		if (this->_vec[i] == num) {
			return (true);
		}
	}
	return (false);
}

unsigned int	Span::size(void) const {
	return (this->_vec.size());
}

unsigned int	Span::maxSize(void) const {
	return (this->_size);
}

unsigned int	Span::shortestSpan(void) const {
	if (this->_vec.size() <= 1) {
		throw (NotEnoughElementException());
	}

	std::vector<int>	tmp(this->_vec);
	unsigned int		min;

	std::sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (size_t i=1; i<tmp.size()-1; i++) {
		if ((unsigned int) tmp[i+1] - tmp[i] < min) {
			min = tmp[i+1] - tmp[i];
		}
	}
	return (min);
}

unsigned int	Span::longestSpan(void) const {
	if (this->_vec.size() <= 1) {
		throw (NotEnoughElementException());
	}

	std::vector<int>	tmp(this->_vec);

	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

void	Span::addNumber(int num) throw(std::exception) {
	if (this->_size < this->_vec.size() + 1) {
		throw std::length_error("Span size exceed maximum allowed size");
	}

	if (this->hasDuplicated(num)) {
		throw (DuplicatedElementException());
	}
	this->_vec.push_back(num);
}

// Operator overloads
int	&Span::operator[](int idx) {
	if (idx < 0 || (int)this->_vec.size() <= idx) {
		throw std::out_of_range("Index out of range");
	}
	return (this->_vec[idx]);
}

int	Span::operator[](int idx) const {
	if (idx < 0 || (int)this->_vec.size() <= idx) {
		throw std::out_of_range("Index out of range");
	}
	return (this->_vec[idx]);
}

// Exception
const char	*Span::DuplicatedElementException::what() const throw() { return ("Duplicated element"); }
const char	*Span::NotEnoughElementException::what() const throw() { return ("Not enough element"); }

std::ostream	&operator<<(std::ostream &os, const Span &rhs) {
	for (size_t i=0; i<rhs.size(); i++) {
		os << rhs[i] << ' ';
	}
	return (os);
}