/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:06:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:45:07 by younhwan         ###   ########.fr       */
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
		virtual		~AMateria(void);
		AMateria	&operator=(const AMateria &ref);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;
		unsigned int		getXP(void) const;
		bool				getEquipped(void) const;

		// Setter
		void				setEquipped(bool equipped);

		// Utils	
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif