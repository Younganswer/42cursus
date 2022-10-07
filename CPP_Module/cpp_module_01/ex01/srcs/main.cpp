/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/07 21:06:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int	main(void) {
	Zombie	*zombies = zombieHorde(10, "younhwan");
	for (int i=0; i<10; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}