#include "../incs/Replace.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "\033[31m" << "Usage: ./replace <filename> <string1> <string2>\n" << "\033[0m";
		return (1);
	}
		
	try {
		Replace::replace(argv[1], argv[2], argv[3]);
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << '\n';
		return (1);
	} catch (...) {
		std::cerr << "\033[31m" << "Error: Unknown error" << "\033[0m" << '\n';
		return (1);
	}
	return (0);
}