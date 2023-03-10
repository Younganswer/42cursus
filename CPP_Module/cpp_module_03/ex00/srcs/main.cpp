#include "../incs/ClapTrap.hpp"
#include <iostream>

int	main(void) {
	{
		ClapTrap	jeolim("jeolim");

		jeolim.attack("Rock");
		jeolim.takeDamage(5);
		jeolim.beRepaired(5);
	}
	{
		ClapTrap	younhwan("younhwan");

		younhwan.takeDamage(5);
		younhwan.takeDamage(5);
		younhwan.beRepaired(10);
	}
	{
		ClapTrap	younhwan("younhwan");

		younhwan.takeDamage(9);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
		younhwan.beRepaired(1);
	}
	return (0);
}