#include "../incs/Zombie.hpp"

int	main(void) {
	{
		randomChump("younhwan");
	}
	{
		Zombie	*hyunkyle = newZombie("hyunkyle");
		hyunkyle->announce();
	}
	{
		Zombie	*daegulee = newZombie("daegulee");
		daegulee->announce();
		delete daegulee;
	}
	// system("PS=`ps | grep ./zombie | head -n 1 | awk '{print $1}'`; leaks $PS > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
	return (0);
}