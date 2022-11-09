/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/09 17:30:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Intern.hpp"

int	main(int argc, char **argv) {
	if (2 < argc) {
		std::cerr << "\033[31mUsage: ./At least this beats coffee-making [target]\033[0m" << '\n';
		return (1);
	}
	try {
		Bureaucrat	younhwan("younhwan", 40);
		Intern		intern;

		std::cout << younhwan;
		
		ShrubberyCreationForm	*shrubbery = (ShrubberyCreationForm *) intern.makeForm("shrubbery creation", "home");
		if (shrubbery) {
			if (argc == 2)
				shrubbery->setTarget(argv[1]);
			std::cout << *shrubbery;
			younhwan.signForm(*shrubbery);
			younhwan.executeForm(*shrubbery);
		}

		RobotomyRequestForm		*robot = (RobotomyRequestForm *) intern.makeForm("robotomy request", "Bender");
		if (robot) {
			std::cout << *robot;
			younhwan.signForm(*robot);
			younhwan.executeForm(*robot);
		}
		
		PresidentialPardonForm	*presi = (PresidentialPardonForm *) intern.makeForm("presidential pardon", "younhwan");
		if (presi) {
			std::cout << *presi;
			younhwan.signForm(*presi);
			younhwan.executeForm(*presi);
		}

	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat	jeolim("jeolim", 1);
		Intern		intern;

		std::cout << jeolim;
		
		PresidentialPardonForm	*presi = (PresidentialPardonForm *) intern.makeForm("presidential pardon", "jeolim");
		if (presi) {
			std::cout << *presi;
			jeolim.signForm(*presi);
			jeolim.executeForm(*presi);
		}
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}