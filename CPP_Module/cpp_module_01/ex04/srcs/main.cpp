#include "../incs/Replace.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "\033[31m" << "Usage: ./replace <filename> <string1> <string2>\n" << "\033[0m";
		return (1);
	}
		
	Replace	replace(argv[1], argv[2], argv[3]);
	if (replace.replace() == false) {
		return (1);
	}
	return (0);
}