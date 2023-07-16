#ifndef TESTER_HPP
# define TESTER_HPP

# include "Converter.hpp"
# include "PmergeMe.hpp"
# include <sys/time.h>
# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <stack>
# include <queue>
# include <map>
# include <set>


class Tester {
	private:
		Tester(void);
		~Tester(void);
		Tester(const Tester &other);
		Tester &operator=(const Tester &other);

	public:
		template <class _Container, class _Tp>
		static bool	run(int argc, char **argv) throw(std::exception);

		template <class _RandomAccessIterator>
		static long	timeToProcess(void (*__ps)(_RandomAccessIterator, _RandomAccessIterator), _RandomAccessIterator __first, _RandomAccessIterator __last) throw(std::exception);

		template <class _Container, class _Tp>
		static std::string	getTypeName(void);
	
	public:
		class InvalidTypeException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

template <class _Container, class _Tp>
bool	Tester::run(int argc, char **argv) throw(std::exception) {
	typedef _Container								container_type;
	typedef _Tp										value_type;
	typedef typename container_type::iterator		iterator;
	typedef typename container_type::const_iterator	const_iterator;

	if (std::is_same<_Tp, int>::value == false && std::is_same<_Tp, float>::value == false && std::is_same<value_type, int>::value == false) {
		throw (std::exception());
	}

	container_type	container;
	long			elapsed;

	for (int i=1; i<argc; i++) {
		container.push_back(Converter::convert(argv[i]));
	}
	std::cout << Tester::getTypeName<container_type, value_type>() << " before sorted: ";
	for (const_iterator it=container.begin(); it!=container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	elapsed = Tester::timeToProcess<iterator>(&PmergeMe::sort<iterator>, container.begin(), container.end());
	std::cout << Tester::getTypeName<container_type, value_type>() << " after sorted: ";
	for (const_iterator it=container.begin(); it!=container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << container.size() << " elements with " << Tester::getTypeName<container_type, value_type>() << ": " << elapsed << "us" << std::endl;
	return (true);
}

template <class _RandomAccessIterator>
long	Tester::timeToProcess(void (*__ps)(_RandomAccessIterator, _RandomAccessIterator), _RandomAccessIterator __first, _RandomAccessIterator __last) throw(std::exception) {
	struct timeval	start, end;
	long			elapsed;

	gettimeofday(&start, NULL);
	__ps(__first, __last);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	return (elapsed);
}

template <class _Container, class _Tp>
std::string	Tester::getTypeName(void) {
	std::string	ret;

	if (typeid(_Container).name() == typeid(std::vector<_Tp>).name()) {
		ret = "std::vector";
	} else if (typeid(_Container).name() == typeid(std::deque<_Tp>).name()) {
		ret = "std::deque";
	} else if (typeid(_Container).name() == typeid(std::list<_Tp>).name()) {
		ret = "std::list";
	} else if (typeid(_Container).name() == typeid(std::stack<_Tp>).name()) {
		ret = "std::stack";
	} else if (typeid(_Container).name() == typeid(std::queue<_Tp>).name()) {
		ret = "std::queue";
	} else if (typeid(_Container).name() == typeid(std::map<_Tp, _Tp>).name()) {
		ret = "std::map";
	} else if (typeid(_Container).name() == typeid(std::set<_Tp>).name()) {
		ret = "std::set";
	} else {
		ret = typeid(_Container).name();
	}
	return (ret);
}

#endif