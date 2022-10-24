/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/24 11:26:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"
#include "../incs/FragTrap.hpp"

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
	return (0);
}