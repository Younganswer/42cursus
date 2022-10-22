/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:48:23 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 17:02:54 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

int	main(void) {
	ScavTrap	jeolim("jeolim");
	ScavTrap	hyunkyle("hyunkyle");

	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.attack(jeolim);
	hyunkyle.guardGate();
	return (0);
}