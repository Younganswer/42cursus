#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	try {
		Bureaucrat				younhwan("younhwan", 40);
		ShrubberyCreationForm	berry("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	presi("presi");

		if (argc == 2) {
			berry.setTarget(argv[1]);
		} else if (2 <= argc) {
			std::cerr << "\033[31m" << "Usage: ./" << argv[0] << " [target]" << "\033[0m" << '\n';
			return (1);
		}

		std::cout << younhwan << '\n';
		std::cout << berry << '\n';
		std::cout << robot << '\n';
		std::cout << presi << '\n';
		younhwan.signForm(berry);
		younhwan.signForm(robot);
		younhwan.signForm(presi);
		younhwan.executeForm(berry);
		younhwan.executeForm(robot);
		younhwan.executeForm(presi);
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat				jeolim("jeolim", 1);
		ShrubberyCreationForm	berry("home");
		RobotomyRequestForm		robot("robot");
		PresidentialPardonForm	presi("presi");

		if (argc == 2) {
			berry.setTarget(argv[1]);
		} else if (2 <= argc) {
			std::cerr << "\033[31m" << "Usage: ./" << argv[0] << " [target]" << "\033[0m" << '\n';
			return (1);
		}

		std::cout << jeolim << '\n';
		std::cout << presi << '\n';
		std::cout << berry << '\n';
		std::cout << robot << '\n';
		jeolim.signForm(berry);
		jeolim.signForm(robot);
		jeolim.signForm(presi);
		jeolim.executeForm(berry);
		jeolim.executeForm(robot);
		jeolim.executeForm(presi);
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	return (0);
}