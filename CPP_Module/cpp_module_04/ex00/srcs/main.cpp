#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"
#include "../incs/WrongAnimal.hpp"
#include "../incs/WrongDog.hpp"
#include "../incs/WrongCat.hpp"
#include <iostream>

int	main(void) {
	{
		const Animal	*meta = new Animal();

		std::cout << "Type: " << meta->getType() << '\n';
		meta->makeSound();
		delete meta;
	}
	std::cout << '\n';
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
	std::cout << '\n';
	{
		const WrongAnimal	*meta = new WrongAnimal();

		std::cout << "Type: " << meta->getType() << '\n';
		meta->makeSound();
		delete meta;
	}
	std::cout << '\n';
	{
		const WrongAnimal	*cat = new WrongCat();

		std::cout << "Type: " << cat->getType() << '\n';
		cat->makeSound();
		delete cat;
	}
	std::cout << '\n';
	{
		const WrongAnimal	*dog = new WrongDog();

		std::cout << "Type: " << dog->getType() << '\n';
		dog->makeSound();
		delete dog;
	}
	system("leaks --quiet $PPID 1> leaks_result 2>/dev/null && cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}