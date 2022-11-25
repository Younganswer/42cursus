/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:33:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:21:34 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanA(void);
		HumanA(const std::string &name, Weapon &weapon);
		HumanA(const HumanA &humanA);
		HumanA	&operator=(const HumanA &humanA);
		~HumanA(void);

		// Utils
		bool	attack(void);
		bool	setWeapon(Weapon &weapon);
};

#endif