#include "../incs/RPN.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
		return (1);
	}

	try {
		int	result = RPN::operate(argv[1]);
		std::cout << "Result: " << result << '\n';
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}