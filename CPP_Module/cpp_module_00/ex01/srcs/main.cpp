#include <iostream>
#include "../incs/PhoneBook.hpp"

static bool	input_is_empty(const std::string &input);
static bool	input_is_invalid(const std::string &input);

int	main(void) {
	PhoneBook phone_book;

	while (true) {
		std::string	cmd;
		std::cout << "Enter command\n>> ";
		getline(std::cin, cmd);
		while (input_is_empty(cmd) || input_is_invalid(cmd)) {
			if (std::cin.eof()) {
				std::cout << '\n';
				return (0);
			} else if (input_is_empty(cmd)) {
				std::cout << "\033[31mError: Input is empty\033[0m\n";
				std::cout << "\033[31mPlease enter valid input\033[0m\n\n";
			} else {
				std::cout << "\033[31mError: Invalid command\033[0m\n";
				std::cout << "\033[31mCommand must be one of \"ADD\" \"SEARCH\" \"EXIT\"\033[0m\n\n";
			}
			std::cout << "Enter command\n>> ";
			getline(std::cin, cmd);
		}
		std::cout << '\n';
		if (cmd.compare("EXIT") == 0)
			break;
		if (cmd.compare("ADD") == 0)
			if (phone_book.add() == false)
				return (0);
		if (cmd.compare("SEARCH") == 0)
			if (phone_book.search() == false)
				return (0);
	}
	return (0);
}

static bool	input_is_empty(const std::string &input) {
	return (input.empty() || input == "\n");
}

static bool	input_is_invalid(const std::string &input) {
	return (input.compare("ADD") && input.compare("SEARCH") && input.compare("EXIT"));
}