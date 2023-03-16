#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Intern.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "\033[31mUsage: ./intern <form> <target>\033[0m" << '\n';
		return (1);
	}

	try {
		Bureaucrat	younhwan("younhwan", 40);
		Intern		intern;
		AForm		*form;

		std::cout << younhwan << '\n';
		form = intern.makeForm(argv[1], argv[2]);
		if (form) {
			std::cout << *form << '\n';
			younhwan.signForm(*form);
			younhwan.executeForm(*form);
			delete form;
		}
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}