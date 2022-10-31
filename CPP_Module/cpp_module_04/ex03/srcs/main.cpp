/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:26:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 14:11:32 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"
#include "../incs/Character.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Floor.hpp"

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
		
		// system("PS=`ps | grep Interface | head -n 1 | awk '{print $1}'`; leaks $PS");
		delete floor;
		delete me;
		delete bob;
		delete src;
	}
	// system("PS=`ps | grep Interface | head -n 1 | awk '{print $1}'`; leaks $PS");
	return (0);
}