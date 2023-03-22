#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const Dog &ref);
		virtual	~Dog(void);
		Dog		&operator=(const Dog &rhs);

		// Util
		virtual void	makeSound(void) const;
};

#endif