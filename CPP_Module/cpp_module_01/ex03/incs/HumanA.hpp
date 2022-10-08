/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:33:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 00:00:28 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
private:
	Weapon		*weapon;
	std::string	name;

public:
	HumanA(void);
	HumanA(const std::string &name, Weapon &weapon);
	HumanA(const HumanA &humanA);
	HumanA	&operator=(const HumanA &humanA);
	~HumanA(void);

	bool	attack(void);
	bool	setWeapon(Weapon &weapon);
};

#endif