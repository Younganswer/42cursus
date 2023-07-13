#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &other) { (void)other; }
PmergeMe	&PmergeMe::operator=(PmergeMe const &other) { (void)other; return (*this); }