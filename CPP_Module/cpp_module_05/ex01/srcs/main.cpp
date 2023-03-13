#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"
#include <iostream>

int	main(void) {
	try {
		Bureaucrat	younhwan("younhwan", 11);
		Form 		f10("F10", 10, 10);
		std::cout << younhwan << '\n';
		std::cout << f10 << '\n';
		younhwan.signForm(f10);
		std::cout << "Test: It will be printed when exception does not occur" << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat	jeolim("jeolim", 1);
		Form 		f1("F1", 1, 1);
		std::cout << jeolim << '\n';
		std::cout << f1 << '\n';
		jeolim.signForm(f1);
		std::cout << f1 << '\n';
		std::cout << "Test: It will be printed when exception does not occur" << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	return (0);
}