/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:30:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/08 23:36:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
private:
	std::string	type;

public:
	Weapon(void);
	Weapon(const std::string type);
	Weapon(const Weapon &weapon);
	Weapon	&operator=(const Weapon &weapon);
	~Weapon(void);
	std::string	getType(void);
	bool		setType(const std::string &type);
};

#endif