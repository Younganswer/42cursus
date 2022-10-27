/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:06:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 12:50:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;
		unsigned int	_xp;
		
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &ref);
		AMateria	&operator=(const AMateria &ref);
		virtual		~AMateria(void);
		
		// Getter
		const std::string	&getType(void) const;
		unsigned int		getXP(void) const;
		
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif