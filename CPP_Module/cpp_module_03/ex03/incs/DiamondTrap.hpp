#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	protected:
		// Getter
		unsigned int	getAttackDamage(void) const;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &diamond_trap);
		~DiamondTrap(void);
		DiamondTrap	&operator=(const DiamondTrap &diamond_trap);

		// Utils
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	whoAmI(void);
};

#endif