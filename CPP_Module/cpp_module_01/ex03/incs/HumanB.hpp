#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*_weapon;
		std::string	_name;
	
		HumanB(void);
		HumanB(const HumanB &humanB);
		HumanB	&operator=(const HumanB &humanB);

	public:
		HumanB(const std::string &name);
		HumanB(const std::string &name, Weapon &weapon);
		~HumanB(void);
	
		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif