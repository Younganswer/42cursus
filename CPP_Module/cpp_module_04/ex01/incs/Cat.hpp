#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &ref);
		virtual ~Cat(void);
		Cat		&operator=(const Cat &ref);

		// Util
		virtual void	makeSound(void) const;
};

#endif