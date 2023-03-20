#include "../incs/BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31m" << "Usage: ./btc <file>" << "\033[0m" << '\n';
		return (1);
	}

	BitcoinExchange	exchanger;

	try {
		exchanger.exchange(argv[1]);
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		return (1);
	} catch (...) {
		std::cerr << "\033[31m" << "Error: Unknown error" << "\033[0m" << '\n';
		return (1);
	}
	return (0);
}