/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:49:48 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 11:40:58 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria	*_materia[4];
		int			_count;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ref);
		virtual	~MateriaSource(void);

		MateriaSource		&operator=(const MateriaSource &ref);

		virtual void		learnMateria(AMateria *mat);
		virtual AMateria	*createMateria(const std::string &type);
};

#endif