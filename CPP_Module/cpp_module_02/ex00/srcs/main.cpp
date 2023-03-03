#include "../incs/Fixed.hpp"
#include <iostream>

int	main(void) {
	{
		Fixed	a;
		a.setRawBits(1234);
		
		Fixed	b(a);
		
		Fixed	c;
		c = b;
		
		std::cout << a.getRawBits() << '\n';
		std::cout << b.getRawBits() << '\n';
		std::cout << c.getRawBits() << '\n';
	}
	return (0);
}