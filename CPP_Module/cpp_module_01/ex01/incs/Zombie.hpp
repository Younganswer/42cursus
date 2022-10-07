/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:40:11 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/07 21:05:24 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
	std::string	name;

public:
	Zombie(void);
	Zombie(std::string name);
	Zombie(const Zombie &zombie);
	Zombie	&operator=(const Zombie &zombie);
	~Zombie(void);

	void	announce(void);
	bool	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif