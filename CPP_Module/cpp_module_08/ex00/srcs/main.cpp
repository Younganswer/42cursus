#include "../incs/easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>

bool	easyfind_with_print(std::vector<int> &v, int target);

int	main(void) {
	{
		std::vector<int>	v;

		for (size_t i=0; i<10; i++) {
			v.push_back(i);
		}
		easyfind_with_print(v, 5);
		std::cout << '\n';
		easyfind_with_print(v, 10);
	}
	return (0);
}

bool	easyfind_with_print(std::vector<int> &v, int target) {
	std::vector<int>::iterator it = easyfind(v, target);

	std::cout << "Searching for " << target << " in vector" << '\n';
	if (it != v.end()) {
		std::cout << "Found: " << *it << " at index " << it - v.begin() << '\n';
	} else {
		std::cout << "\033[31m" << "Error: " << "Not found: " << target << " is not in vector" << "\033[0m" << '\n';
	}
	return (true);
}