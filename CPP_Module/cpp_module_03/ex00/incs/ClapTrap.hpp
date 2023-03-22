#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &ref);
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &rhs);
	
		// Utils
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif