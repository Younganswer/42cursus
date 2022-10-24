/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:01:16 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/24 11:16:38 by younhwan         ###   ########.fr       */
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
	
public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clap_trap);
	ClapTrap	&operator=(const ClapTrap &clap_trap);
	virtual	~ClapTrap(void);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string		getName(void);
	unsigned int	getHitPoints(void);
	unsigned int	getEnergePoints(void);
	unsigned int	getAttackDamage(void);

	void			setName(const std::string &name);
	void			setHitPoints(unsigned int amount);
	void			setEnergePoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
};

#endif