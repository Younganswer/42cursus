/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:22 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:19:51 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string _type;
		
	public:
		Animal(void);
		Animal(const std::string &type);		
		Animal(const Animal &ref);
		virtual ~Animal(void);
		Animal	&operator=(const Animal& ref);
		
		// Getter
		std::string			getType(void);
		const std::string	&getType(void) const;

		// Util
		virtual void		makeSound(void) const;
};

#endif