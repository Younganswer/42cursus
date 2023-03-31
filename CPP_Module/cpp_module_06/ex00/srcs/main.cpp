#include "../incs/Convert.hpp"
#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "\033[31m" << "Usage: ./" << argv[0] << " [string]\33[0m" << '\n';
		return (1);
	}

	std::cout << std::fixed;
	std::cout.precision(1);
	return (Convert::convert(argv[1]) == false);
}