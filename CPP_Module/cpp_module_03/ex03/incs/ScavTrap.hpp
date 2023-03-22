#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	protected:
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		~ScavTrap(void);
		ScavTrap	&operator=(const ScavTrap &rhs);

		// Util
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif