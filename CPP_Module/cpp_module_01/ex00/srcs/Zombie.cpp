#include "../incs/Zombie.hpp"

Zombie::Zombie(void): _name(std::string()) {}
Zombie::Zombie(const std::string &name): _name(name) {}
Zombie::Zombie(const Zombie &zombie): _name(zombie._name) {}
Zombie::~Zombie(void) { std::cout << _name << " is destroyed\n"; }

Zombie	&Zombie::operator=(const Zombie &zombie) {
	if (this != &zombie) {
		this->~Zombie();
		new (this) Zombie(zombie);
	}
	return (*this);
}

void	Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }
