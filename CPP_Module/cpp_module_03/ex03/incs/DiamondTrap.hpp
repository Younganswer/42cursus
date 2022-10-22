/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:21:43 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 19:14:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string	_name;
	using FragTrap::hit_points;
	using ScavTrap::energy_points;
	using FragTrap::attack_damage;
	
public:
	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &diamond_trap);
	DiamondTrap	&operator=(const DiamondTrap &diamond_trap);
	~DiamondTrap(void);

	using ScavTrap::attack;
	
	void	whoAmI(void);
};

#endif