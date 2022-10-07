/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:54:29 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/07 20:57:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int	main(void) {
	randomChump("younhwan");
	Zombie	*hyunkyle = newZombie("hyunkyle");
	hyunkyle->announce();
	delete hyunkyle;
	return (0);
}