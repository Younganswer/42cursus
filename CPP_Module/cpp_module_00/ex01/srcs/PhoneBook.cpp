/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:24:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/02 21:19:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/PhoneBook.hpp"

PhoneBook::PhoneBook(void): first_pos(0), cur_pos(0) {
	return;
}

bool	PhoneBook::print_field(const std::string &str) {
	for (unsigned long i=0; str.length()<10 && i<10-str.length(); i++) {
		std::cout << ' ';
	}
	for (unsigned long i=0; i<str.length() && i<10; i++) {
		std::cout << str[i];
	}
	return (true);
}

bool	PhoneBook::add(void) {
	std::cout << "Enter first name\n>> ";
	std::cin >> contacts[cur_pos].first_name;
	std::cout << "Enter last name\n>> ";
	std::cin >> contacts[cur_pos].last_name;
	std::cout << "Enter nickname\n>> ";
	std::cin >> contacts[cur_pos].nick_name;
	std::cout << "Enter darkest secret\n>> ";
	std::cin >> contacts[cur_pos].darkest_secret;
	std::cout << "Enter phone number\n>> ";
	std::cin >> contacts[cur_pos].phone_number;
	contacts[cur_pos].initialized = true;
	cur_pos = (cur_pos + 1) % 8;
	if (cur_pos == first_pos)
		first_pos++;
	return (true);
}

bool	PhoneBook::search(void) {
	for (int i=0; i<8; i++) {
		if (contacts[(first_pos + i) % 8].initialized) {
			print_field(std::to_string(i));
			std::cout << '|';
			print_field(contacts[(first_pos + i) % 8].first_name);
			std::cout << '|';
			print_field(contacts[(first_pos + i) % 8].last_name);
			std::cout << '|';
			print_field(contacts[(first_pos + i) % 8].nick_name);
			std::cout << '\n';
		}
	}
	long long	idx;
	std::cout << "Enter index of phonebook\n>> ";
	std::cin >> idx;
	while (idx < 0 || 8 <= idx) {
		std::cout << "\033[31mError: Invalid index\033[0m\n";
		std::cout << "\033[31mIndex must be one of (0, 1, 2, 3, 4, 5, 6, 7)\033[0m\n";
		std::cout << "Enter index of phonebook\n>> ";
		std::cin >> idx;
	}
	if (!contacts[(first_pos + idx) % 8].initialized) {
		std::cout << "NULL\n";
		return (true);
	}
	std::cout << std::to_string((first_pos + idx) % 8) << '\n';
	std::cout << contacts[(first_pos + idx) % 8].first_name << '\n';
	std::cout << contacts[(first_pos + idx) % 8].last_name << '\n';
	std::cout << contacts[(first_pos + idx) % 8].nick_name << '\n';
	return (true);
}

PhoneBook::~PhoneBook(void) {
	return;
}