#include "../incs/Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31m" << "Usage: ./" << argv[0] << " <Things to complain>\033[0m" << '\n';
		return (0);
	}
	
	Harl	harl;

	switch (hash(argv[1])) {
		case DEBUG:
			harl.complain("DEBUG");
		case INFO:
			harl.complain("INFO");
		case WARNING:
			harl.complain("WARNING");
		case ERROR:
			harl.complain("ERROR");
			break;
		default:
			harl.complain("UNDEFINED");
			break;
	}
	return (0);
}