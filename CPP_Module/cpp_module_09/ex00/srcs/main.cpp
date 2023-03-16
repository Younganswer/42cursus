#include "../incs/BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31m" << "Usage: ./btc <file>" << "\033[0m" << '\n';
		return (1);
	}

	BitcoinExchange	*exchange = NULL;

	try {
		exchange = new BitcoinExchange(argv[1]);
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		return (1);
	}
	exchange->print();
	
	return (0);
}