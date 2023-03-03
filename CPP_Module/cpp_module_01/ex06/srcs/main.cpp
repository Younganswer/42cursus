#include "../incs/Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "\033[31mUsage: ./harlFilter <Things to complain>\033[0m" << '\n';
		return (0);
	}
	
	Harl	harl;
	switch (harl.hash(argv[1]))
	{
	case harl.hash("debug"):
		harl.complain("debug");
	
	default:
		break;
	}
	return (0);
}