#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_size;

		Span(void);

	public:
		Span(unsigned int n);
		Span(const Span &ref);
		~Span(void);
		Span	&operator=(const Span &rhs);

		// Utils
		void	addNumber(int num);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		
		bool			print(void) const;
		unsigned int	size(void) const;
		unsigned int	maxSize(void) const;

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

#endif