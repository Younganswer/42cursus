#include "../incs/Harl.hpp"

int	main(void) {
	{
		Harl	harl;

		harl.complain("DEBUG");
		std::cout << '\n';
		harl.complain("INFO");
		std::cout << '\n';
		harl.complain("WARNING");
		std::cout << '\n';
		harl.complain("ERROR");
		std::cout << '\n';
		harl.complain("UNDEFINED");
	}
	return (0);
}