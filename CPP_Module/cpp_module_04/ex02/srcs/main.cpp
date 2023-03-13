#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include <iostream>

int	main(void) {
	//{
	//	const Animal	*meta = new Animal();

	//	std::cout << "Type: " << meta->getType() << '\n';
	//	meta->makeSound();
	//	delete meta;
	//}
	//std::cout << '\n';
	{
		const Animal	*cat = new Cat();

		std::cout << "Type: " << cat->getType() << '\n';
		cat->makeSound();
		delete cat;
	}
	std::cout << '\n';
	{
		const Animal	*dog = new Dog();

		std::cout << "Type: " << dog->getType() << '\n';
		dog->makeSound();
		delete dog;
	}
	return (0);
}