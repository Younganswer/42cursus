#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base(void) {}

Base	*generate(void) {
	Base	*ret = NULL;
	int		rand_num = rand() % 3;

	if (rand_num == 0)
		ret = new A;
	else if (rand_num == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void	identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "This is A class" << '\n';
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "This is B class" << '\n';
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "This is C class" << '\n';
	} else {
		std::cerr << "\033[31m" << "Error: Base *p is not created by its derived class" << "\033[0m" << '\n';
	}
}

void	identify_from_reference(Base &ref) {
	try {
		A &a = dynamic_cast<A &>(ref);

		(void) a;
		std::cout << "This is A class" << '\n';
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(ref);

			(void) b;
			std::cout << "This is B class" << '\n';
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(ref);

				(void) c;
				std::cout << "This is C class" << '\n';
			} catch (std::exception &e) {
				std::cerr << "\033[31m" << "Error: Base &ref is not created by its derived class" << "\033[0m" << '\n';
			}
		}
	}
}