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
		const Animal *meta = new Animal();
		std:: cout << meta->getType() << " " << '\n';
		meta->makeSound();
		delete meta;
	}
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
	return (0);
}