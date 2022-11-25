/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:40:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:16:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie(void);
		Zombie(const std::string &name);
		Zombie(const Zombie &zombie);
		Zombie	&operator=(const Zombie &zombie);
		~Zombie(void);
	
		// Setter
		bool	setName(std::string name);
	
		// Util
		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif