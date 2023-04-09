#include "../incs/iter.hpp"

int	main(void) {
	{
		const int	arr[5] = {0, 1, 2, 3, 4};

		ft::iter(arr, 5, ft::print);
	}
	std::cout << '\n';
	{
		const std::string	arr[9] = {"Hello", " ", "World", "!", "\n", "I'm", " ", "Younhwan", "\n"};

		ft::iter(arr, 9, ft::print);
	}
	return (0);
}