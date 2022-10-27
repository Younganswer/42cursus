/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:44:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain	*brain;

	public:
		Dog(void);
		Dog(const Dog &ref);
		Dog	&operator=(const Dog &ref);
		virtual ~Dog(void);
		virtual void makeSound(void) const;
};

#endif