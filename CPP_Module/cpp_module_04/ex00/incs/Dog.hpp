/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:28 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:22:15 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const Dog &ref);
		virtual	~Dog(void);
		Dog		&operator=(const Dog &ref);

		// Util
		virtual void	makeSound(void) const;
};

#endif