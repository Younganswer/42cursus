#include "../incs/easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>

int	main(void) {
	{
		std::vector<int>	v;

		for (size_t i=0; i<10; i++) {
			v.push_back(i);
		}

		{
			int	toFind = 5;

			std::cout << "Searching for " << toFind << " in vector" << '\n';
			try {
				std::vector<int>::iterator it = easyfind(v, 5);
				std::cout << "Found: " << *it << " at index " << it - v.begin() << '\n';
			} catch (std::exception &e) {
				std::cout << "\033[31m" << "Error: " << e.what() << ": " << toFind << " is not in vector" << "\033[0m" << '\n';
			}
		}
		std::cout << '\n';
		{
			int	toFind = 10;

			std::cout << "Searching for " << toFind << " in vector" << '\n';
			try {
				std::vector<int>::iterator it = easyfind(v, 10);
				std::cout << "Found: " << *it << " at index " << it - v.begin() << '\n';
			} catch (std::exception &e) {
				std::cout << "\033[31m" << "Error: " << e.what() << ": " << toFind << " is not in vector" << "\033[0m" << '\n';
			}
		}
	}
	return (0);
}