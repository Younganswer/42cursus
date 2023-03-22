#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria	*_materia[4];
		int			_count;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ref);
		virtual			~MateriaSource(void);
		MateriaSource	&operator=(const MateriaSource &rhs);

		// Utils
		virtual void		learnMateria(AMateria *mat);
		virtual AMateria	*createMateria(const std::string &type) const;
};

#endif