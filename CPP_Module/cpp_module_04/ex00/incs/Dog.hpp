/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:23:40 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const Dog &ref);
		Dog	&operator=(const Dog &ref);
		virtual ~Dog(void);
		virtual void makeSound(void) const;
};

#endif