#include "../incs/Span.hpp"
#include <iostream>

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
		this->_size = rhs._size;
		this->_vec.clear();
		for (size_t i=0; i<rhs._vec.size(); i++) {
			this->_vec.push_back(rhs._vec[i]);
		}
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
		throw NotEnoughException();
	}

	unsigned int	min=UINT_MAX, diff=0;

	for (size_t i=0; i<this->_vec.size()-1; i++) {
		for (size_t j=i+1; j<this->_vec.size(); j++) {
			diff = this->_vec[j] - this->_vec[i];
			if (diff < min) {
				min = diff;
			}
		}
	}
	return (min);
}

unsigned int	Span::longestSpan(void) const {
	if (this->_vec.size() <= 1) {
		throw NotEnoughException();
	}

	unsigned int	max=0, diff=0;

	for (size_t i=0; i<this->_vec.size()-1; i++) {
		for (size_t j=i+1; j<this->_vec.size(); j++) {
			diff = this->_vec[j] - this->_vec[i];
			if (diff > max) {
				max = diff;
			}
		}
	}
	return (max);
}

void	Span::addNumber(int num) throw(std::exception) {
	if (this->_size < this->_vec.size() + 1) {
		throw std::length_error("Span size exceed maximum allowed size");
	}

	if (this->hasDuplicated(num)) {
		throw DuplicatedException();
	}
	this->_vec.push_back(num);
}

template < class InputIterator >
Span::iterator	Span::insert(const_iterator pos, InputIterator first, InputIterator last) throw(std::exception) {
	if (this->_size < this->_vec.size() + (last - first)) {
		throw std::length_error("Span size exceed maximum allowed size");
	}

	for (InputIterator it=first; it!=last; it++) {
		if (this->hasDuplicated(*it)) {
			throw DuplicatedException();
		}
	}

	iterator	it = this->_vec.begin() + (pos - this->_vec.begin());
	iterator	it2 = this->_vec.end() - 1;
	iterator	it3 = it2 + (last - first);

	for (int i=0; i<(int)(last - first); i++) {
		this->_vec.push_back(0);
	}

	for (int i=0; i<(int)(it2 - it + 1); i++) {
		*(it3 - i) = *(it2 - i);
	}

	for (int i=0; i<(int)(last - first); i++) {
		*(it + i) = *(first + i);
	}

	return (it);
}

// Operator overloads
int	&Span::operator[](int idx) {
	if (idx < 0 || idx >= (int)this->_vec.size()) {
		throw std::out_of_range("Index out of range");
	}
	return (this->_vec[idx]);
}

int	Span::operator[](int idx) const {
	if (idx < 0 || idx >= (int)this->_vec.size()) {
		throw std::out_of_range("Index out of range");
	}
	return (this->_vec[idx]);
}

// Exception: Duplicated
Span::DuplicatedException::DuplicatedException(void) {}
Span::DuplicatedException::~DuplicatedException(void) throw() {}
const char	*Span::DuplicatedException::what() const throw() {
	return ("Duplicated number");
}

// Exception: Not enough numbers
Span::NotEnoughException::NotEnoughException(void) {}
Span::NotEnoughException::~NotEnoughException(void) throw() {}
const char	*Span::NotEnoughException::what() const throw() {
	return ("Not enough numbers");
}

std::ostream	&operator<<(std::ostream &os, const Span &rhs) {
	for (size_t i=0; i<rhs.size(); i++) {
		os << rhs[i] << ' ';
	}
	return (os);
}