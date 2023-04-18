#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter {
	public:
		virtual ~ICharacter(void);

		// Getter
		virtual const std::string	&getName(void) const = 0;

		// Utils
		virtual void	equip(AMateria *mat) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

#endif