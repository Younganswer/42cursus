#include "../incs/MateriaSource.hpp"
#include "../incs/Character.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Floor.hpp"
#include <iostream>

int	main(void) {
	{
		Floor	*floor = new Floor();
		
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter		*me = new Character("me");
		floor->setMateria(src->createMateria("ice"));
		me->equip(floor->getMateria(0));
		floor->setMateria(src->createMateria("cure"));
		me->equip(floor->getMateria(1));

		ICharacter		*bob = new Character("bob");
		bob->equip(floor->getMateria(1)); // Cannot equip that is already equipped
		
		me->use(0, *bob);
		me->use(1, *bob);

		bob->use(0, *bob); // So, cannot use

		me->unequip(1); // Floor[1] points that unequipped materia
		
		system("leaks $PPID 1> leaks_result 2>/dev/null && cat leaks_result | grep leaked && rm -rf leaks_result");
		delete floor;
		delete me;
		delete bob;
		delete src;
	}
	system("leaks $PPID 1> leaks_result 2>/dev/null && cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}