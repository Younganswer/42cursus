#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &ref);
		virtual		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &rhs);
	
		// Utils
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif