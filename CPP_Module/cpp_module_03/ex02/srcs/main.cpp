/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:42:01 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"
#include "../incs/FragTrap.hpp"

int	main(void) {
	ClapTrap	jeolim("jeolim");
	ScavTrap	hyunkyle("hyunkyle");
	FragTrap	daegulee("dagulee");

	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.guardGate();
	daegulee.highFivesGuys();
	return (0);
}