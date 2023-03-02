#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*_weapon;
		std::string	_name;
	
	public:
		HumanB(void);
		HumanB(const std::string &name);
		HumanB(const std::string &name, Weapon &weapon);
		HumanB(const HumanB &humanB);
		HumanB	&operator=(const HumanB &humanB);
		~HumanB(void);
	
		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif