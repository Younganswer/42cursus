/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macatn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:26:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:29:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"
#include "../incs/Dog.hpp"
#include "../incs/Cat.hpp"

int	main(void) {
	{
		const Animal *dog = new Dog();
		std::cout << dog->getType() << " " << '\n';
		dog->makeSound();
		delete dog;
	}
	{
		const Animal *cat = new Cat();
		std::cout << cat->getType() << " " << '\n';
		cat->makeSound(); //will output the cat sound!
		delete cat;
	}
	// {
	// 	const Animal *animal;
	// 	try {
	// 		animal = new Animal();
	// 	} catch (std::exception &e) {
	// 		std::cout << e.what() << '\n';
	// 	}
	// }
	return (0);
}