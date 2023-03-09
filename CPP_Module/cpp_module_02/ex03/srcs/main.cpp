#include "../incs/Fixed.hpp"
#include "../incs/Point.hpp"
#include <iostream>

int	main(void) {
	{
		Point	a(0, 0), b(0, 3), c(4, 0);
		Point	target(2, 1);
		std::cout << "Target is ";
		std::cout << ((Point::bsp(a, b, c, target)) ? "inside" : "outside or on the line");
		std::cout <<  " of the triangle\n";
	}
	return (0);
}