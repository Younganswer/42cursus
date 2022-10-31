/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:26:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:35:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"
#include "../incs/Character.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Ice.hpp"

int	main(void) {
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter		*me = new Character("me");
		AMateria		*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter		*bob = new Character("bob");
		bob->equip(tmp); // Cannot equip that is already equipped
		
		me->use(0, *bob);
		me->use(1, *bob);

		bob->use(0, *bob); // So, cannot use
		
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}