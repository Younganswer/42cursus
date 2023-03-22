#include "../incs/Array.hpp"
#include <iostream>
#include <string>

int	main(void) {
	{
		Array<int>	arr(5);

		for (int i=0; i<5; i++) {
			arr[i] = i;
		}
		for (int i=0; i<5; i++) {
			try {
				std::cout << arr[i] << ' ';
			} catch (std::exception &e) {
				std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
			}
		}
		std::cout << '\n';
		try {
			std::cout << arr[-1] << '\n';
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Array<std::string>	arr(9);
		std::string			str[9] = {"Hello", " ", "World", "!", "\n", "I'm", " ", "younhwan", "\n"};
		for (int i=0; i<9; i++) {
			arr[i] = str[i];
		}
		for (int i=0; i<9; i++) {
			try {
				std::cout << arr[i];
			} catch (std::exception &e) {
				std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
			}
		}
	}
	return (0);
}