/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:38:46 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(void) {
	name.clear();
	return;
}

Zombie::Zombie(std::string name) {
	this->name = name.c_str();
	return;
}

Zombie::Zombie(const Zombie &zombie) {
	(*this) = zombie;
}

Zombie	&Zombie::operator=(const Zombie &zombie) {
	if (this == &zombie)
		return (*this);

	this->name = zombie.name.c_str();
	return (*this);
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
	return;
}

bool	Zombie::setName(std::string name) {
	this->name = name.c_str();
	return (true);
}

Zombie::~Zombie(void) {
	std::cout << name << ": is destroyed\n";
	return;
}