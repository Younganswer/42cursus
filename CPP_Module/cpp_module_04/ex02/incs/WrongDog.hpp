#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongDog: public WrongAnimal {
	private:
		Brain	*_brain;

	public:
		WrongDog(void);
		WrongDog(const WrongDog &ref);
		~WrongDog(void);
		WrongDog	&operator=(const WrongDog &ref);

		// Util
		void	makeSound(void) const;
};

#endif