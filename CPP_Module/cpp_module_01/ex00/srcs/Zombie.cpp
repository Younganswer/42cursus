#include "../incs/Zombie.hpp"

Zombie::Zombie(void): _name(std::string()) {}
Zombie::Zombie(const std::string &name): _name(name) {}
Zombie::Zombie(const Zombie &ref): _name(ref._name) {}
Zombie::~Zombie(void) { std::cout << _name << " is destroyed\n"; }

Zombie	&Zombie::operator=(const Zombie &rhs) {
	if (this != &rhs) {
		this->~Zombie();
		new (this) Zombie(rhs);
	}
	return (*this);
}

void	Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }
