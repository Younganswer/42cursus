#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <file>" << '\n';
		return (1);
	}

	try {
		// TODO:
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}