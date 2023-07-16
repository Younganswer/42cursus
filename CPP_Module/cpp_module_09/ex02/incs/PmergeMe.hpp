#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class PmergeMe {
	private:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
	
	public:
		template <typename _RandomAccessIterator>
		static void	sort(_RandomAccessIterator __first, _RandomAccessIterator __last);
	
	private:
		template <typename _RandomAccessIterator>
		static void	__insertion_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last);

		template <typename _RandomAccessIterator>
		static void	__insertion_sort_j(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last);

		static int	__jacobsthal(int __n);
};

// Ford-Johnson merge-insertion sort algorithm
template <typename _RandomAccessIterator>
void	PmergeMe::sort(_RandomAccessIterator __first, _RandomAccessIterator __last) {
	typedef typename std::iterator_traits<_RandomAccessIterator>::value_type	value_type;

	std::vector<value_type>	__main_chain, __sub_chain;
	_RandomAccessIterator	__middle = __first + (__last - __first) / 2;

	if (__first + 1 == __last) {
		return ;
	}
	for (_RandomAccessIterator __it=__first; __it!=__last; __it+=2) {
		if (__it + 1 == __last) {
			__sub_chain.push_back(*__it);
			break ;
		}
		if (*__it < *(__it + 1)) {
			std::iter_swap(__it, __it + 1);
		}
		__main_chain.push_back(*__it);
		__sub_chain.push_back(*(__it + 1));
	}
	for (_RandomAccessIterator __it=__first; __it!=__middle; ++__it) {
		*__it = __main_chain[__it - __first];
	}
	for (_RandomAccessIterator __it=__middle; __it!=__last; ++__it) {
		*__it = __sub_chain[__it - __middle];
	}
	sort(__first, __middle);
	__insertion_sort(__first, __middle, __last);
}

template <typename _RandomAccessIterator>
void	PmergeMe::__insertion_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last) {
	_RandomAccessIterator	__first2 = __middle, __last2;
	int						__i = 2, __j = __jacobsthal(__i);

	while (true) {
		__last2 = __middle + __j;
		if (__last < __last2) {
			__last2 = __last;
		}
		__insertion_sort_j(__first, __first2, __last2);
		if (__last2 == __last) {
			break ;
		}
		__first2 = __last2;
		++__i;
		__j = __jacobsthal(__i);
	}
}

template <typename _RandomAccessIterator>
void	PmergeMe::__insertion_sort_j(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last) {
	_RandomAccessIterator	__t;

	while (__middle != __last) {
		for (_RandomAccessIterator __it=__last-1; __it!=__middle; --__it) {
			std::iter_swap(__it - 1, __it);
		}
		__t = std::lower_bound(__first, __middle, *__middle);
		for (_RandomAccessIterator __it=__middle; __it!=__t; --__it) {
			std::iter_swap(__it - 1, __it);
		}
		++__middle;
	}
}

#endif