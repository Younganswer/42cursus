#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include <iostream>

int	main(void) {
	{
		Animal** const	meta = new Animal*[100];
		for (int i=0; i<50; i++) {
			meta[i] = new Dog();
		}
		for (int i=50; i<100; i++) {
			meta[i] = new Cat();
		}
		for (int i=0; i<100; i++) {
			delete meta[i];
		}
		delete[] meta;
	}
	return (0);
}