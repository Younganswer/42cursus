/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:47:24 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:51:47 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Floor {
	private:
		AMateria	*_materia[1024];
		size_t		_count;

	public:
		Floor(void);
		Floor(const Floor &ref);
		~Floor(void);
		Floor& operator=(const Floor &ref);

		//	Getter
		AMateria	*getMateria(size_t idx) const;

		//	Setter
		void		setMateria(AMateria *materia);
};

#endif