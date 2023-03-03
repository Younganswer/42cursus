#include "../incs/Replace.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid arguments\nUsage: ./replace <filename> <string1> <string2>" << '\n';
		return (1);
	}
		
	Replace	replace(argv[1], argv[2], argv[3]);
	try {
		if (replace.replace() == false) {
			return (1);
		}
	} catch (std::string err) {
		std::cerr << "\033[31m" << "Error: " << err << "\033[0m" << '\n';
		return (1);
	}
	return (0);
}