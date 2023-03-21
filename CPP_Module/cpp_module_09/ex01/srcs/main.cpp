#include "../incs/RPN.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31m" << "Usage: ./btc <file>" << "\033[0m" << '\n';
		return (1);
	}

	int	result;

	try {
		result = RPN::operate(argv[1]);
		std::cout << "Result: " << result << '\n';
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		return (1);
	} catch (...) {
		std::cerr << "\033[31m" << "Error: Unknown error" << "\033[0m" << '\n';
		return (1);
	}
	return (0);
}