#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	protected:
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &Frag_trap);
		~FragTrap(void);
		FragTrap	&operator=(const FragTrap &Frag_trap);

		// Util
		void	highFivesGuys(void);
};

#endif