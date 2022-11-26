/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:05:05 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:47:00 by younhwan         ###   ########.fr       */
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
		virtual		~Character(void);
		Character	&operator=(const Character &ref);

		// Getter
		virtual std::string			getName(void);
		virtual const std::string	&getName(void) const;

		// Utils
		virtual void				equip(AMateria *mat);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
};

#endif