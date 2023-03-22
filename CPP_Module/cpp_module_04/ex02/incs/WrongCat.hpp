#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal {
	private:
		Brain	*_brain;

	public:
		WrongCat(void);
		WrongCat(const WrongCat &ref);
		~WrongCat(void);
		WrongCat	&operator=(const WrongCat &rhs);

		// Util
		void	makeSound(void) const;
};

#endif