#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie(void);
		Zombie(const std::string &name);
		Zombie(const Zombie &ref);
		~Zombie(void);
		Zombie	&operator=(const Zombie &rhs);
	
		// Setter
		bool	setName(std::string name);
	
		// Util
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif