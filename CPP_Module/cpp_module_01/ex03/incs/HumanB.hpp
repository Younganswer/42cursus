/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:33:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:21:32 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*_weapon;
		std::string	_name;
	
	public:
		HumanB(void);
		HumanB(const std::string &name);
		HumanB(const std::string &name, Weapon &weapon);
		HumanB(const HumanB &humanB);
		HumanB	&operator=(const HumanB &humanB);
		~HumanB(void);
	
		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif