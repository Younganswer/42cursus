#ifndef TESTER_HPP
# define TESTER_HPP

# include "Converter.hpp"
# include "PmergeMe.hpp"
# include <sys/time.h>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <vector>
# include <deque>
# include <list>
# include <stack>
# include <queue>
# include <set>


class Tester {
	private:
		static const size_t	MAX_WIDTH = 80;

	private:
		Tester(void);
		~Tester(void);
		Tester(const Tester &other);
		Tester &operator=(const Tester &other);

	public:
		template <class _Container>
		static bool	run(int argc, char **argv) throw(std::exception);

	private:
		template <class _Container>
		static std::stringstream	__header(void);

		template <class _Container>
		static std::stringstream	__container(const _Container &container);

		template <class _RandomAccessIterator>
		static long	__timeToProcess(void (*__ps)(_RandomAccessIterator, _RandomAccessIterator), _RandomAccessIterator __first, _RandomAccessIterator __last) throw(std::exception);

		template <class _Container>
		static std::string	__getTypeName(void);

		template <class _Container>
		static std::stringstream	__footer(size_t __sz, long	__elapsed);
	
	public:
		class InvalidTypeException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

template <class _Container>
bool	Tester::run(int argc, char **argv) throw(std::exception) {
	typedef _Container							container_type;
	typedef typename container_type::iterator	iterator;

	container_type	container;
	long			elapsed;

	std::cout << Tester::__header<container_type>().str() << std::endl << std::endl;
	for (int i=1; i<argc; i++) {
		container.push_back(Converter::convert(argv[i]));
	}
	std::cout << Tester::__getTypeName<container_type>() << " before sorted" << std::endl;
	std::cout << Tester::__container<container_type>(container).str() << std::endl << std::endl;
	elapsed = Tester::__timeToProcess<iterator>(&PmergeMe::sort<iterator>, container.begin(), container.end());
	std::cout << Tester::__getTypeName<container_type>() << " after sorted" << std::endl;
	std::cout << Tester::__container<container_type>(container).str() << std::endl << std::endl;
	std::cout << Tester::__footer<container_type>(container.size(), elapsed).str() << std::endl;
	return (true);
}

template <class _Container>
std::stringstream	Tester::__header(void) {
	typedef _Container	container_type;

	std::string			content = "Test with " + Tester::__getTypeName<container_type>();
	size_t				padding = (Tester::MAX_WIDTH - content.length()) / 2;
	std::stringstream	ret;

	ret << "\033[34m";
	ret << std::setw(Tester::MAX_WIDTH) << std::setfill('-') << "" << std::endl;
	ret << "|" << std::setw(padding) << std::setfill(' ') << "" << content;
	ret << ((padding % 2) ? std::setw(padding) : std::setw(padding - 1));
	ret << std::setfill(' ') << "|" << std::endl;
	ret << std::setw(Tester::MAX_WIDTH) << std::setfill('-') << "";
	ret << "\033[0m";
	return (ret);
}

template <class _Container>
std::stringstream Tester::__container(const _Container& container) {
    typedef _Container 								container_type;
    typedef typename container_type::const_iterator	const_iterator;

    std::stringstream	ret, tmp;
	std::string			str;

    for (const_iterator it = container.begin(); it != container.end(); it++) {
        tmp << *it << " ";
    }
	str = tmp.str();
	for (size_t i=1; i<str.length(); i++) {
		if (i % Tester::MAX_WIDTH == 0) {
			ret << std::endl;
		}
		ret << str[i];
	}
	return (ret);
}

template <class _RandomAccessIterator>
long	Tester::__timeToProcess(void (*__ps)(_RandomAccessIterator, _RandomAccessIterator), _RandomAccessIterator __first, _RandomAccessIterator __last) throw(std::exception) {
	struct timeval	start, end;
	long			elapsed;

	gettimeofday(&start, NULL);
	__ps(__first, __last);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	return (elapsed);
}

template <class _Container>
std::string	Tester::__getTypeName(void) {
	typedef _Container						container_type;
	typedef typename _Container::value_type	value_type;

	std::string	ret;

	if (typeid(container_type).name() == typeid(std::vector<value_type>).name()) {
		ret = "std::vector";
	} else if (typeid(container_type).name() == typeid(std::deque<value_type>).name()) {
		ret = "std::deque";
	} else if (typeid(container_type).name() == typeid(std::list<value_type>).name()) {
		ret = "std::list";
	} else if (typeid(container_type).name() == typeid(std::stack<value_type>).name()) {
		ret = "std::stack";
	} else if (typeid(container_type).name() == typeid(std::queue<value_type>).name()) {
		ret = "std::queue";
	} else if (typeid(container_type).name() == typeid(std::set<value_type>).name()) {
		ret = "std::set";
	} else {
		ret = typeid(container_type).name();
	}
	return (ret);
}

template <class _Container>
std::stringstream	Tester::__footer(size_t __sz, long	__elapsed) {
	typedef _Container	container_type;

	std::stringstream	ret;

	ret << "Time to process a range of " << __sz << " elements with " << Tester::__getTypeName<container_type>() << ": " << __elapsed << "us";
	return (ret);
}

#endif