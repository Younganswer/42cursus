#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	protected:
		std::string _type;
		WrongAnimal(const std::string &type);

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &ref);
		~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &rhs);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Util
		void		makeSound(void) const;
};

#endif