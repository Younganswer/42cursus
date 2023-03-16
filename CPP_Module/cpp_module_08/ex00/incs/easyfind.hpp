#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class NotFoundException: public std::exception {
	public:
		NotFoundException(void);
		NotFoundException(NotFoundException const &src);
		~NotFoundException(void) throw();
		NotFoundException &operator=(NotFoundException const &rhs);
		virtual const char *what() const throw();
};

NotFoundException::NotFoundException(void) {}
NotFoundException::NotFoundException(NotFoundException const &src) { *this = src; }
NotFoundException::~NotFoundException(void) throw() {}
NotFoundException	&NotFoundException::operator=(NotFoundException const &rhs) {
	(void) rhs;
	return (*this);
}
const char *NotFoundException::what() const throw() {
	return ("Not Found");
}

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return (it);
}

#endif