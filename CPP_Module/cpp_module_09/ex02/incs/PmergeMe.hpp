#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
};

// Ford-Johnson merge-insertion sort algorithm
template <typename _RandomAccessIterator>
void	PmergeMe::sort(_RandomAccessIterator __first, _RandomAccessIterator __last) {
	std::sort(__first, __last);
}

#endif