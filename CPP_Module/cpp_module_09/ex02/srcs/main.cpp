#include "Converter.hpp"
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <num1> [num2] [num3] [...]" << '\n';
		return (1);
	}

	try {
		std::vector<int>	vector;
		std::deque<int>		deque;

		for (int i=1; i<argc; i++) {
			vector.push_back(Converter::convert(argv[i]));
			deque.push_back(Converter::convert(argv[i]));
		}
		PmergeMe::sort(vector.begin(), vector.end());
		PmergeMe::sort(deque.begin(), deque.end());
		for (std::vector<int>::const_iterator it=vector.begin(); it!=vector.end(); it++) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
		for (std::deque<int>::const_iterator it=deque.begin(); it!=deque.end(); it++) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}