/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:15:44 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:27:56 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scav_trap);
	ScavTrap	&operator=(const ScavTrap &scav_trap);
	~ScavTrap(void);

	void	guardGate(void);
};

#endif