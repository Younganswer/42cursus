/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:30:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:20:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(const std::string type);
		Weapon(const Weapon &weapon);
		Weapon	&operator=(const Weapon &weapon);
		~Weapon(void);

		// Getter
		std::string			getType(void);
		const std::string	getType(void) const;

		// Setter
		bool		setType(const std::string &type);
};

#endif