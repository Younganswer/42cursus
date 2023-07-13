#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &other) { (void)other; }
PmergeMe	&PmergeMe::operator=(PmergeMe const &other) { (void)other; return (*this); }

int	PmergeMe::__jacobsthal(int __n) {
	int	__j0 = 0, __j1 = 1, __j2 = 1;

	if (__n == 0) {
		return (__j0);
	}
	if (__n == 1) {
		return (__j1);
	}
	if (__n == 2) {
		return (__j2);
	}
	for (int i=3; i<=__n; ++i) {
		__j0 = __j1;
		__j1 = __j2;
		__j2 = __j1 + 2*__j0;
	}
	return (__j2);
}