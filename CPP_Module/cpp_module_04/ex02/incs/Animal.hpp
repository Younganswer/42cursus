#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	protected:
		std::string _type;
		
	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &ref);
		virtual ~Animal(void);
		Animal	&operator=(const Animal& ref);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Util
		virtual void		makeSound(void) const = 0;
};

#endif