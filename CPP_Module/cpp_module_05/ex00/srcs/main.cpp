/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/01 13:44:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	bureaucrat("younhwan", 150);
		std::cout << bureaucrat;
		bureaucrat.incGrade();
		std::cout << bureaucrat;
		bureaucrat.decGrade();
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	bureaucrat("jeolim", 1);
		std::cout << bureaucrat;
		bureaucrat.decGrade();
		std::cout << bureaucrat;
		bureaucrat.incGrade();
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	bureaucrat("hyunkyle", 0);
		std::cout << bureaucrat;
		bureaucrat.incGrade();
		std::cout << bureaucrat;
		bureaucrat.decGrade();
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	bureaucrat("daegulee", 151);
		std::cout << bureaucrat;
		bureaucrat.incGrade();
		std::cout << bureaucrat;
		bureaucrat.decGrade();
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}