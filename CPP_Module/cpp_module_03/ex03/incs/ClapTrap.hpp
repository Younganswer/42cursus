/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:01:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:47:07 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

	std::string		getName(void) const ;
	unsigned int	getHitPoints(void) const ;
	unsigned int	getEnergePoints(void) const ;
	unsigned int	getAttackDamage(void) const ;

	void			setName(const std::string &name);
	void			setHitPoints(unsigned int amount);
	void			setEnergePoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
	
	void			takeDamage(unsigned int amount);
	
public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clap_trap);
	ClapTrap	&operator=(const ClapTrap &clap_trap);
	virtual		~ClapTrap(void);

	void		attack(ClapTrap &target);
	void		beRepaired(unsigned int amount);

};

#endif