#include "../incs/DiamondTrap.hpp"

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
	{
		FragTrap	dagulee("dagulee");
		dagulee.attack("Wheel");
		dagulee.takeDamage(20);
		dagulee.beRepaired(20);
		dagulee.highFivesGuys();
	}
	{
		DiamondTrap	younhwan("younhwan");
		younhwan.attack("Wall");
		younhwan.takeDamage(30);
		younhwan.beRepaired(30);
		younhwan.guardGate();
		younhwan.highFivesGuys();
		younhwan.whoAmI();
	}
	return (0);
}