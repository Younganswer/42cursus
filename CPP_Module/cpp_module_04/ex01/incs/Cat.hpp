/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:25:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:28:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;
		
	public:
		Cat(void);
		Cat(const Cat &ref);
		virtual ~Cat(void);
		Cat		&operator=(const Cat &ref);

		// Util
		virtual void makeSound(void) const;
};

#endif