/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:06:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:35:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
class ICharacter;

class AMateria {
	protected:
		std::string		_type;
		unsigned int	_xp;
		bool			_equipped;
		
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &ref);
		AMateria	&operator=(const AMateria &ref);
		virtual		~AMateria(void);
		
		// Getter
		const std::string	&getType(void) const;
		unsigned int		getXP(void) const;
		bool				getEquipped(void) const;

		// Setter
		void				setEquipped(bool equipped);
		
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif