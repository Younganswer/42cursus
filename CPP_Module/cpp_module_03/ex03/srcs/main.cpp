/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:44:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

int	main(void) {
	ClapTrap	jeolim("jeolim");
	ScavTrap	hyunkyle("hyunkyle");
	FragTrap	daegulee("dagulee");
	DiamondTrap	younhwan("younhwan");

	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	jeolim.beRepaired(100);
	hyunkyle.attack(jeolim);
	hyunkyle.guardGate();
	daegulee.highFivesGuys();
	younhwan.whoAmI();
	return (0);
}