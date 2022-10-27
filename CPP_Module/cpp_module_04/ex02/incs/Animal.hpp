/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:59:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(const std::string &type);		
		Animal(const Animal &ref);
		Animal	&operator=(const Animal& ref);
		virtual ~Animal(void);
		
		virtual void 	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif