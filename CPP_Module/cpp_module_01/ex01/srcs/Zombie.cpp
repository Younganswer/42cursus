#include "../incs/Zombie.hpp"
#include <iostream>

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

// Setter
bool	Zombie::setName(std::string name) { this->_name = std::string(name.c_str()); return (true); }

// Util
void	Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }