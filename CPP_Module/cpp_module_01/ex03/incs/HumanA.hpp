#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		Weapon		*_weapon;
		std::string	_name;

		HumanA(void);

	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA(void);

		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif