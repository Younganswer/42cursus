/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:13:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/29 16:41:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

int	main(void) {
	try {
		Bureaucrat	younhwan("younhwan", 11);
		Form 		f10("F10", 10, 10);
		std::cout << younhwan << f10;
		younhwan.signForm(f10);
		std::cout << "Test: It is shown when exception is not catched" << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	try {
		Bureaucrat	jeolim("jeolim", 1);
		Form 		f1("F1", 1, 1);
		std::cout << jeolim << f1;
		jeolim.signForm(f1);
		std::cout << f1;
		std::cout << "Test: It is shown when exception is not catched" << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
	} catch (...) {
		std::cout << "\033[31m" << "Error: Unknown Error" << "\033[0m" << '\n';
	}
	return (0);
}