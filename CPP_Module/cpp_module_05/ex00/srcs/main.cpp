#include "../incs/Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	try {
		Bureaucrat	younhwan("younhwan", 1);

		std::cout << younhwan << '\n';
		younhwan.decGrade();
		std::cout << younhwan << '\n';
		younhwan.incGrade();
		std::cout << younhwan << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat	jeolim("jeolim", 150);

		std::cout << jeolim << '\n';
		jeolim.incGrade();
		std::cout << jeolim << '\n';
		jeolim.decGrade();
		std::cout << jeolim << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat	hyunkyle("hyunkyle", 0);
		std::cout << hyunkyle << '\n';
		hyunkyle.incGrade();
		std::cout << hyunkyle << '\n';
		hyunkyle.decGrade();
		std::cout << hyunkyle << '\n';
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cerr << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat	daegulee("daegulee", 151);
		std::cout << daegulee << '\n';
		daegulee.incGrade();
		std::cout << daegulee << '\n';
		daegulee.decGrade();
		std::cout << daegulee << '\n';
	} catch (std::exception &e) {
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cerr << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	return (0);
}