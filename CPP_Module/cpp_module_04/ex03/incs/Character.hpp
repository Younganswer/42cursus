#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &ref);
		virtual		~Character(void);
		Character	&operator=(const Character &rhs);

		// Getter
		virtual const std::string	&getName(void) const;

		// Utils
		virtual void	equip(AMateria *mat);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
};

#endif