#include "../incs/Array.hpp"
#include <iostream>
#include <string>

int	main(void) {
	{
		Array<int>	arr(5);

		std::cout << "Size of array: " << arr.size() << '\n';
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
		const std::string	str[9] = {"Hello", " ", "World", "!", "\n", "I'm", " ", "younhwan", "\n"};

		std::cout << "Size of array: " << arr.size() << '\n';
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
	std::cout << '\n';
	system("leaks $PPID 2>/dev/null 1>leaks_result && cat leaks_result | grep leaked && rm leaks_result");
	return (0);
}