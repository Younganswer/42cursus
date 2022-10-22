/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:01:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 17:02:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;

protected:
	void			setName(const std::string &name);
	std::string		getName(void);
	void			setHitPoints(unsigned int amount);
	unsigned int	getHitPoints(void);
	void			setEnergePoints(unsigned int amount);
	unsigned int	getEnergePoints(void);
	void			setAttackDamage(unsigned int amount);
	unsigned int	getAttackDamage(void);
	
public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clap_trap);
	ClapTrap	&operator=(const ClapTrap &clap_trap);
	virtual	~ClapTrap(void);

	void	attack(ClapTrap &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif