#include "Tester.hpp"
#include <iostream>
#include <vector>
#include <deque>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <num1> [num2] [num3] [...]" << '\n';
		return (1);
	}

	try {
		Tester::run< std::vector<int> >(argc, argv);
		std::cout << std::endl;
		Tester::run< std::deque<int> >(argc, argv);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}