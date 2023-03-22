#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &ref);
		~FragTrap(void);
		FragTrap	&operator=(const FragTrap &rhs);

		// Util
		void	highFivesGuys(void);
};

#endif