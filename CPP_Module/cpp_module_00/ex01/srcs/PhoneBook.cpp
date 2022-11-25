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

int	PhoneBook::getIndex(void) {
	int	ret;

	std::cout << "Enter index of phonebook\n>> ";
	std::cin >> ret;
	while ((ret < 0 || 8 <= ret) || _contacts[(_first_pos + ret) % 8].getInitialized() == false) {
		if (ret < 0 || 8 <= ret) {
			std::cout << "\033[31m" << "Error: Invalid index" << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Index must be one of [0, 1, 2, 3, 4, 5, 6, 7]" << "\033[0m" << '\n';
		} else {
			std::cout << "\033[31m" << "Error: No record at index " << ret << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Please enter valid index" << "\033[0m" << '\n';
		}
		std::cout << "Enter index of phonebook\n>> ";
		std::cin >> ret;
	}
	return (ret);
}

bool	PhoneBook::printPhoneBook(void) {
	for (int i=0; i<8; i++) {
		if (_contacts[(_first_pos + i) % 8].getInitialized()) {
			printField(std::to_string(i));
			std::cout << '|';
			printField(_contacts[(_first_pos + i) % 8].getFirstName());
			std::cout << '|';
			printField(_contacts[(_first_pos + i) % 8].getLastName());
			std::cout << '|';
			printField(_contacts[(_first_pos + i) % 8].getNickName());
			std::cout << '\n';
		}
	}
	return (true);
}

bool	PhoneBook::printRecord(int idx) {
	std::cout << std::to_string((_first_pos + idx) % 8) << '\n';
	std::cout << _contacts[(_first_pos + idx) % 8].getFirstName() << '\n';
	std::cout << _contacts[(_first_pos + idx) % 8].getLastName() << '\n';
	std::cout << _contacts[(_first_pos + idx) % 8].getNickName() << '\n';
	return (true);
}

bool	PhoneBook::printField(const std::string &str) {
	for (size_t i=0; str.length()<10 && i<10-str.length(); i++) {
		std::cout << ' ';
	}
	for (size_t i=0; i<str.length() && i<10; i++) {
		std::cout << str[i];
	}
	return (true);
}

PhoneBook::PhoneBook(void): _first_pos(0), _cur_pos(0) {}

PhoneBook::~PhoneBook(void) {}

bool	PhoneBook::add(void) {
	std::string	objects[] = {
		"first name",
		"last name",
		"nickname",
		"darkest secret",
		"phone number"
	};
	void	(Contact::*setters[])(const std::string &str) = {
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickName,
		&Contact::setDarkestSecret,
		&Contact::setPhoneNumber
	};

	for (int i=0; i<5; i++) {
		std::string tmp;
		std::cout << "Enter " << objects[i] << '\n' << ">> ";
		std::cin >> tmp;
		(_contacts[_cur_pos].*setters[i])(tmp);
	}
	
	_contacts[_cur_pos].setInitialized(true);

	_cur_pos = (_cur_pos + 1) % 8;
	if (_cur_pos == _first_pos)
		_first_pos++;

	return (true);
}

bool	PhoneBook::search(void) {
	printPhoneBook();	
	printRecord(getIndex());
	return (true);
}