/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:50:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 21:07:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/phone_book.hpp"

int	main(void) {
	Phone_book phone_book;
	while (true) {
		std::string	cmd;
		std::cout << "Enter command\n>> ";
		std::cin >> cmd;
		while (cmd.compare("ADD") && cmd.compare("SEARCH") && cmd.compare("EXIT")) {
			std::cout << "\033[31mError: Invalid command\033[0m\n";
			std::cout << "\033[31mCommand must be one of \"ADD\" \"SEARCH\" \"EXIT\"\033[0m\n";
			std::cout << "Enter command\n>> ";
			std::cin >> cmd;
		}
		if (!cmd.compare("EXIT"))
			break;
		if (!cmd.compare("ADD"))
			phone_book.add();
		if (!cmd.compare("SEARCH"))
			phone_book.search();
	}
	return (0);
}