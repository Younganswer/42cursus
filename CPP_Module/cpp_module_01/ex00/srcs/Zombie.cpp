/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/07 20:52:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(void) {
	name.clear();
	return;
}

Zombie::Zombie(std::string name) {
	this->name.append(name);
	return;
}

Zombie::Zombie(const Zombie &zombie) {
	(*this) = zombie;
}

Zombie	&Zombie::operator=(const Zombie &zombie) {
	if (this == &zombie)
		return (*this);

	this->name.clear();
	this->name.append(zombie.name);
	return (*this);
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
	return;
}

Zombie::~Zombie(void) {
	std::cout << name << ": is destroyed\n";
	return;
}