#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	public:
		// Iterator
		typedef std::vector<int>::iterator			iterator;
		typedef std::vector<int>::const_iterator	const_iterator;

	private:
		std::vector<int>	_vec;
		unsigned int		_size;

		Span(void);

		iterator	begin(void);
		iterator	end(void);

		// Operator overloads
		int	&operator[](int idx);

		bool	hasDuplicated(int num) const;

	public:
		~Span(void);
		Span(unsigned int n);
		Span(const Span &ref);
		Span	&operator=(const Span &rhs);

		// Iterator
		const_iterator	cbegin(void) const;
		const_iterator	cend(void) const;

		// Utils
		unsigned int	size(void) const;
		unsigned int	maxSize(void) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			addNumber(int num) throw(std::exception);

		template < class InputIterator >
		iterator	insert(const_iterator pos, InputIterator first, InputIterator last) throw(std::exception);

		// Operator overloads
		int	operator[](int idx) const;

		// Exception: Duplicated
		class DuplicatedException: public std::exception {
			public:
				DuplicatedException(void);
				virtual ~DuplicatedException(void) throw();
				virtual const char* what() const throw();
		};

		// Exception: Not enough numbers
		class NotEnoughException: public std::exception {
			public:
				NotEnoughException(void);
				virtual ~NotEnoughException(void) throw();
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Span &rhs);



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
	iterator	it2 = this->_vec.end();
	iterator	it3 = this->_vec.end();

	while (it2 != it) {
		it2--;
		it3--;
		*it3 = *it2;
	}

	while (first != last) {
		*it = *first;
		it++;
		first++;
	}

	return (it);
}

#endif