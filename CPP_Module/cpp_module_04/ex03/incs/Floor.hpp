#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <string>
# include "AMateria.hpp"

class Floor {
	private:
		AMateria	*_materia[1024];
		size_t		_count;

		Floor(const Floor &ref);
		Floor& operator=(const Floor &ref);

	public:
		Floor(void);
		~Floor(void);

		//	Getter
		AMateria	*getMateria(size_t idx) const;

		//	Setter
		void		setMateria(AMateria *materia);
};

#endif