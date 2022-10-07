/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:58:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/07 21:06:12 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*ret = new Zombie[N];
	
	for (int i=0; i<N; i++) {
		ret[i].setName(name);
	}
	return (ret);
}