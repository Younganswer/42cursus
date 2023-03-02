#include "../incs/HumanA.hpp"
#include "../incs/HumanB.hpp"

int	main(void) {
	{
		Weapon	club = Weapon("crude spiked club");
	
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// system("leaks $PPID > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
	return (0);
}