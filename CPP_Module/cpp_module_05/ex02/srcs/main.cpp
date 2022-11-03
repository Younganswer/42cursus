/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/03 15:55:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"

int	main(int argc, char **argv) {
	try {
		Bureaucrat				younhwan("younhwan", 40);
		ShrubberyCreationForm	berry("home");
		if (argc == 2) {
			berry.setTarget(argv[1]);
		} else if (2 <= argc) {
			std::cerr << "\033[31mUsage: ./No, you need form 28B, not 28C... [target]\033[0m" << '\n';
			return (1);
		}
		RobotomyRequestForm		robot("younhwan");
		PresidentialPardonForm	presi("younhwan");
		std::cout << younhwan << berry << robot << presi;
		younhwan.signForm(berry);
		younhwan.signForm(robot);
		younhwan.signForm(presi);
		younhwan.executeForm(berry);
		younhwan.executeForm(robot);
		younhwan.executeForm(presi);
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat				jeolim("jeolim", 1);
		PresidentialPardonForm	presi("jeolim");
		std::cout << jeolim << presi;
		jeolim.signForm(presi);
		jeolim.executeForm(presi);
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}