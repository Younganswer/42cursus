#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
	public:
		WrongDog(void);
		WrongDog(const WrongDog &ref);
		~WrongDog(void);
		WrongDog	&operator=(const WrongDog &ref);

		// Util
		void	makeSound(void) const;
};

#endif