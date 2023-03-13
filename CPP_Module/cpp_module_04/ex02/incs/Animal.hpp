#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	protected:
		std::string _type;

		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &ref);
		Animal	&operator=(const Animal& ref);
		
	public:
		virtual ~Animal(void);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Util
		virtual void		makeSound(void) const;
};

#endif