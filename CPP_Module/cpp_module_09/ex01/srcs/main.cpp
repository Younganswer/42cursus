#include "../incs/RPN.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31m" << "Usage: ./btc <file>" << "\033[0m" << '\n';
		return (1);
	}

	RPN::operate(argv[1]);
	return (0);
}