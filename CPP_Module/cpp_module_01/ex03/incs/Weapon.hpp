#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(const std::string &type);
		Weapon(const Weapon &ref);
		~Weapon(void);
		Weapon	&operator=(const Weapon &rhs);

		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Setter
		bool		setType(const std::string &type);
};

#endif