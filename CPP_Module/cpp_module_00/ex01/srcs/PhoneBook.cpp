#include "../incs/PhoneBook.hpp"
#include <iostream>

const std::string	objects[] = {
	"first name",
	"last name",
	"nickname",
	"darkest secret",
	"phone number"
};
bool	(Contact::*const setInfo[])(std::string str) = {
	&Contact::setFirstName,
	&Contact::setLastName,
	&Contact::setNickName,
	&Contact::setDarkestSecret,
	&Contact::setPhoneNumber
};
const std::string	&(Contact::*const getInfo[])(void) const = {
	&Contact::getFirstName,
	&Contact::getLastName,
	&Contact::getNickName,
	&Contact::getDarkestSecret,
	&Contact::getPhoneNumber
};

static bool	input_is_empty(const std::string &input);

PhoneBook::PhoneBook(void): _first_pos(0), _cur_pos(0) {}

PhoneBook::~PhoneBook(void) {}

bool	PhoneBook::add(void) {
	for (int i=0; i<5; i++) {
		std::string input;
		std::cout << "Enter " << objects[i] << '\n' << ">> ";
		getline(std::cin, input);
		while (input_is_empty(input)) {
			std::cout << "\033[31m" << "Error: Input is empty" << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Pleaes enter valid input" << "\033[0m" << "\n\n";
			std::cout << "Enter " << objects[i] << '\n' << ">> ";
			getline(std::cin, input);
		}
		(_contacts[_cur_pos].*setInfo[i])(input);
	}
	_contacts[_cur_pos].setInitialized(true);

	_cur_pos = (_cur_pos + 1) % 8;
	if (_cur_pos == _first_pos)
		_first_pos++;

	std::cout << '\n';
	return (true);
}

bool	PhoneBook::search(void) {
	printPhoneBook();
	printRecord(getIndex());
	return (true);
}

int	PhoneBook::getIndex(void) {
	std::string	input;
	int			ret;

	std::cout << "Enter index of phonebook\n>> ";
	getline(std::cin, input);
	while (true) {
		if (input.compare("EXIT") == 0)
			return (-1);
		while (input_is_empty(input)) {
			std::cout << "\033[31m" << "Error: Input is empty" << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Pleaes enter valid input" << "\033[0m" << '\n';
			std::cout << "If you want to exit \"SEARCH\", enter EXIT\n\n";
			std::cout << "Enter index of phonebook\n>> ";
			getline(std::cin, input);
		}
		try {
			ret = std::stoi(input);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: Invalid index" << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Index must be one of [0, 1, 2, 3, 4, 5, 6, 7]" << "\033[0m" << '\n';
			std::cout << "If you want to exit \"SEARCH\", enter EXIT\n\n";
			std::cout << "Enter index of phonebook\n>> ";
			getline(std::cin, input);
			continue ;
		}
		if (ret < 0 || 7 <= ret) {
			std::cout << "\033[31m" << "Error: Invalid index" << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Index must be one of [0, 1, 2, 3, 4, 5, 6, 7]" << "\033[0m" << '\n';
			std::cout << "If you want to exit \"SEARCH\", enter EXIT\n\n";
			std::cout << "Enter index of phonebook\n>> ";
			getline(std::cin, input);
			continue ;
		}
		if (_contacts[(_first_pos + ret) % 8].getInitialized() == false) {
			std::cout << "\033[31m" << "Error: No record at index " << ret << "\033[0m" << '\n';
			std::cout << "\033[31m" << "Please enter valid index" << "\033[0m" << '\n';
			std::cout << "If you want to exit \"SEARCH\", enter EXIT\n\n";
			std::cout << "Enter index of phonebook\n>> ";
			getline(std::cin, input);
			continue ;
		}
		break;
	}
	std::cout << '\n';
	return (ret);
}

bool	PhoneBook::printPhoneBook(void) {
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << "----------|----------|----------|----------\n";
	for (int i=0; i<8; i++) {
		printField(std::to_string(i));
		std::cout << '|';
		printField(_contacts[(_first_pos + i) % 8].getFirstName());
		std::cout << '|';
		printField(_contacts[(_first_pos + i) % 8].getLastName());
		std::cout << '|';
		printField(_contacts[(_first_pos + i) % 8].getNickName());
		std::cout << '\n';
	}
	return (true);
}

bool	PhoneBook::printRecord(int idx) {
	if (idx == -1)
		return (true);

	for (int i=0; i<5; i++) {
		std::cout << objects[i] << ": ";
		std::cout << (_contacts[(_first_pos + idx) % 8].*getInfo[i])() << '\n';
	}
	std::cout << '\n';
	return (true);
}

bool	PhoneBook::printField(const std::string &str) {
	if (10 < str.length()) {
		std::cout << str.substr(0, 9) << '.';
	} else {
		for (size_t i=0; i<10-str.length(); i++)
			std::cout << ' ';
		std::cout << str;
	}
	return (true);
}

static bool	input_is_empty(const std::string &input) {
	return (input.empty() || input == "\n");
}