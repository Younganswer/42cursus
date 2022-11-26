/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:58:13 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:50:40 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "Character.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(const Cure &ref);
		virtual	~Cure(void);
		Cure	&operator=(const Cure &ref);

		// Utils
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif