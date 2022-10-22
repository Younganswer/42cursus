/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:15:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:28:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &Frag_trap);
	FragTrap	&operator=(const FragTrap &Frag_trap);
	~FragTrap(void);

	void	highFivesGuys(void);
};

#endif