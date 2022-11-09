/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/09 13:10:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	younhwan("younhwan", 150);
		std::cout << younhwan;
		younhwan.incGrade();
		std::cout << younhwan;
		younhwan.decGrade();
		std::cout << younhwan;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	jeolim("jeolim", 1);
		std::cout << jeolim;
		jeolim.decGrade();
		std::cout << jeolim;
		jeolim.incGrade();
		std::cout << jeolim;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	hyunkyle("hyunkyle", 0);
		std::cout << hyunkyle;
		hyunkyle.incGrade();
		std::cout << hyunkyle;
		hyunkyle.decGrade();
		std::cout << hyunkyle;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	try {
		Bureaucrat	daegulee("daegulee", 151);
		std::cout << daegulee;
		daegulee.incGrade();
		std::cout << daegulee;
		daegulee.decGrade();
		std::cout << daegulee;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} catch (...) {
		std::cout << "\033[31mError: Unknown Error\033[0m" << '\n';
	}
	return (0);
}