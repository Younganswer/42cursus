/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:05:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:01:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &ref);
		Character	&operator=(const Character &ref);
		virtual	~Character(void);

		// Getter
		virtual const std::string	&getName(void) const;

		virtual void				equip(AMateria *mat);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
};

#endif