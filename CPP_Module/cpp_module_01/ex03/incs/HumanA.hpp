#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanA(void);
		HumanA(const std::string &name, Weapon &weapon);
		HumanA(const HumanA &humanA);
		HumanA	&operator=(const HumanA &humanA);
		~HumanA(void);

		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif