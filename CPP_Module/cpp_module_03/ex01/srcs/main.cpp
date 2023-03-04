#include "../incs/ClapTrap.hpp"
#include "../incs/ScavTrap.hpp"

int	main(void) {
	{
		ClapTrap	jeolim("jeolim");
		jeolim.attack("Rock");
		jeolim.takeDamage(5);
		jeolim.beRepaired(5);
	}
	{
		ScavTrap	hyunkyle("hyunkyle");
		hyunkyle.attack("Tree");
		hyunkyle.takeDamage(10);
		hyunkyle.beRepaired(10);
		hyunkyle.guardGate();
	}
	return (0);
}