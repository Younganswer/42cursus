#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void);

		// Utils
		virtual void		learnMateria(AMateria *mat) = 0;
		virtual AMateria	*createMateria(std::string const &type) const = 0;
};

#endif