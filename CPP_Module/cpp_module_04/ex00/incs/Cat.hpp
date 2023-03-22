#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(const Cat &ref);
		virtual ~Cat(void);
		Cat		&operator=(const Cat &rhs);

		// Util
		virtual void	makeSound(void) const;
};

#endif