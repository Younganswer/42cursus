#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"
# include "Character.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(const Cure &ref);
		virtual	~Cure(void);
		Cure	&operator=(const Cure &rhs);

		// Utils
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif