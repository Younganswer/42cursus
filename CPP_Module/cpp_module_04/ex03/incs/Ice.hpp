/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:49:20 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:09:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "Character.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(const std::string &type);
		Ice(const Ice &ref);
		Ice		&operator=(const Ice &ref);
		virtual	~Ice(void);
		
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif