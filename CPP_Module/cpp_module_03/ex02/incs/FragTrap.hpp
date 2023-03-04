#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &Frag_trap);
		~FragTrap(void);
		FragTrap	&operator=(const FragTrap &Frag_trap);

		// Util
		void	highFivesGuys(void);
};

#endif