/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:14:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(void) {
	this->_name = std::string();
	return;
}

Zombie::Zombie(const std::string &name) {
	this->_name = std::string(name.c_str());
	return;
}

Zombie::Zombie(const Zombie &zombie) {
	(*this) = zombie;
}

Zombie	&Zombie::operator=(const Zombie &zombie) {
	if (this != &zombie) {
		this->_name = std::string(zombie._name.c_str());
	}
	return (*this);
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
	return;
}

Zombie::~Zombie(void) {
	std::cout << _name << " is destroyed\n";
	return;
}