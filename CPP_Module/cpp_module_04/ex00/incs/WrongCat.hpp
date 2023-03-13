#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &ref);
		~WrongCat(void);
		WrongCat	&operator=(const WrongCat &ref);

		// Util
		void	makeSound(void) const;
};

#endif