/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:44:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string _type;
		
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &ref);
		Animal	&operator=(const Animal& ref);
		
	public:
		virtual ~Animal(void);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Util
		virtual void		makeSound(void) const;
};

#endif