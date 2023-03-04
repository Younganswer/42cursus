#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
	protected:
		// Getter
		std::string			getName(void);
		const std::string	&getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergePoints(void) const;
		unsigned int		getAttackDamage(void) const;
	
		// Setter
		bool	setName(const std::string &name);
		bool	setHitPoints(unsigned int amount);
		bool	setEnergePoints(unsigned int amount);
		bool	setAttackDamage(unsigned int amount);
		
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &clap_trap);
		virtual		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &clap_trap);
	
		// Utils
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif