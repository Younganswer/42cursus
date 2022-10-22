/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 16:01:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

int	main(void) {
	ClapTrap	jeolim("jeolim");
	ClapTrap	hyunkyle("hyunkyle");

	hyunkyle.setEnergePoint(2);
	hyunkyle.setAttackDamage(5);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	return (0);
}