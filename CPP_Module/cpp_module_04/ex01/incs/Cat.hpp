/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:25:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:43:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*brain;
		
	public:
		Cat(void);
		Cat(const Cat &ref);
		Cat	&operator=(const Cat &ref);
		virtual ~Cat(void);
		virtual void makeSound(void) const;
};

#endif