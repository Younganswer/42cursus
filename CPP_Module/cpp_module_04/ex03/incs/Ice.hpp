#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"
# include "Character.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(const std::string &type);
		Ice(const Ice &ref);
		virtual	~Ice(void);
		Ice		&operator=(const Ice &rhs);
		
		// Utils
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif