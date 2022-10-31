/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:47:30 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:21:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria *mat) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif