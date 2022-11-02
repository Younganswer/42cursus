/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/02 11:31:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

int	main(void) {
	try {
		Bureaucrat	bureaucrat("younhwan", 11);
		Form 		form("F10", 10, 10);
		std::cout << bureaucrat << form;
		bureaucrat.signForm(form);
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	bureaucrat("jeolim", 1);
		Form 		form("F1", 1, 1);
		std::cout << bureaucrat << form;
		bureaucrat.signForm(form);
		std::cout << form;
	} catch (std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}