#include "../incs/Fixed.hpp"
#include <iostream>

int	main(void) {
	{
		Fixed	a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << '\n';
		std::cout << ++a << '\n';
		std::cout << a << '\n';
		std::cout << a++ << '\n';
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << Fixed::max(a, b) << '\n';
		try {
			std::cout << a / Fixed(0) << '\n';
		} catch (std::exception &e) {
			std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	{
		Fixed	a, b;

		a = 10.0f;
		b.setRawBits(-1);
		std::cout << a / b << '\n';
	}
	return (0);
}