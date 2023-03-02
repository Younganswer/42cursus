/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:26 by younhwan          #+#    #+#             */
/*   Updated: 2023/03/02 10:52:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie(void) { this->_name = std::string(); }
Zombie::Zombie(const std::string &name) { this->_name = std::string(name.c_str()); }
Zombie::Zombie(const Zombie &zombie) { (*this) = zombie; }
Zombie::~Zombie(void) { std::cout << _name << " is destroyed\n"; }

Zombie	&Zombie::operator=(const Zombie &zombie) {
	if (this != &zombie) {
		this->_name = std::string(zombie._name.c_str());
	}
	return (*this);
}

void	Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }
